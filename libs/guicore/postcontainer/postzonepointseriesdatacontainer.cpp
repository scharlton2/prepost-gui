#include "../misc/cgnsfileopener.h"
#include "../project/projectcgnsfile.h"
#include "../project/projectdata.h"
#include "../project/projectmainfile.h"
#include "postcalculatedresult.h"
#include "postcalculatedresultargument.h"
#include "postsolutioninfo.h"
#include "postzonedatacontainer.h"
#include "posttimesteps.h"
#include "postzonepointseriesdatacontainer.h"

#include <misc/stringtool.h>

#include <QRegExp>

#include <cgnslib.h>
#include <cmath>

PostZonePointSeriesDataContainer::PostZonePointSeriesDataContainer(PostSolutionInfo::Dimension dim, const std::string& zoneName, const QString& pName, int pointIndex, GridLocation_t gridLocation, PostSolutionInfo* sinfo) :
	PostSeriesDataContainer(dim, sinfo),
	m_zoneName (zoneName),
	m_zoneId {0},
	m_physName {pName},
	m_pointIndex {pointIndex},
	m_gridLocation {gridLocation}
{}

const QList<double>& PostZonePointSeriesDataContainer::data() const
{
	return m_data;
}

bool PostZonePointSeriesDataContainer::handleCurrentStepUpdate(const int /*fn*/)
{
	return true;
}

void PostZonePointSeriesDataContainer::update(const int fn)
{
	loadFromCgnsFile(fn);
}

const std::string& PostZonePointSeriesDataContainer::zoneName() const
{
	return m_zoneName;
}

QString PostZonePointSeriesDataContainer::caption() const
{
	return zoneName().c_str();
}

int PostZonePointSeriesDataContainer::pointIndex() const
{
	return m_pointIndex;
}

void PostZonePointSeriesDataContainer::setPointIndex(int index)
{
	m_pointIndex = index;
}

GridLocation_t PostZonePointSeriesDataContainer::gridLocation() const
{
	return m_gridLocation;
}

void PostZonePointSeriesDataContainer::setGridLocation(GridLocation_t location)
{
	m_gridLocation = location;
}

bool PostZonePointSeriesDataContainer::setZoneId(const int fn)
{
	// if m_zoneID is already set, we do not have to do it again.
	if (m_zoneId != 0) {return true;}

	int ier;
	int numZones;
	ier = cg_nzones(fn, m_baseId, &numZones);
	if (ier != 0) {return false;}
	for (int Z = 1; Z <= numZones; ++Z) {
		char zonename[32];
		ier = cg_zone_read(fn, m_baseId, Z, zonename, m_sizes);
		if (ier != 0) {return false;}
		if (m_zoneName == zonename) {
			m_zoneId = Z;
			return true;
		}
	}
	return false;
}

bool PostZonePointSeriesDataContainer::loadData(const int fn)
{
	return loadData(fn, m_gridLocation);
}

bool PostZonePointSeriesDataContainer::loadData(const int fn, GridLocation_t location)
{
	m_data.clear();
	auto zc = zoneDataContainer();

	std::vector<PostCalculatedResult*> calcResults = zc->calculatedResults();
	for (PostCalculatedResult* r : calcResults) {
		r->updateFunction();
	}

	bool ret = setZoneId(fn);
	if (! ret) {return false;}

	QRegExp rx("^(.+) \\(magnitude\\)$");
	bool magnitude = (rx.indexIn(m_physName) != -1);
	QString physName = m_physName;
	if (magnitude) {
		// shortname
		physName = rx.cap(1);
	}

	int ier;
	int numSols;
	double value;
	char solname[32];
	GridLocation_t loc;

	if (postSolutionInfo()->resultSeparated()) {
		int numTimes = projectData()->mainfile()->postSolutionInfo()->timeSteps()->timesteps().length();
		for (int i = 0; i < numTimes; ++i) {
			CgnsFileOpener o(resultCgnsFileNameForStep(i), CG_MODE_READ);
			ier = cg_nsols(o.fileId(), m_baseId, m_zoneId, &numSols);
			if (ier != 0) {return false;}

			for (int j = 1; j <= numSols; ++j) {
				ier = cg_sol_info(o.fileId(), m_baseId, m_zoneId, j, solname, &loc);
				if (ier != 0) {return false;}
				if (location != loc) {continue;}
				ier = cg_goto(o.fileId(), m_baseId, "Zone_t", m_zoneId, "FlowSolution_t", j, "end");
				if (ier != 0) {return false;}
				bool ok = loadData(physName, magnitude, &value);
				if (! ok) {return false;}
				m_data.push_back(value);
			}
		}
	} else {
		ier = cg_nsols(fn, m_baseId, m_zoneId, &numSols);
		if (ier != 0) {return false;}

		for (int i = 1; i <= numSols; ++i) {
			ier = cg_sol_info(fn, m_baseId, m_zoneId, i, solname, &loc);
			if (ier != 0) {return false;}
			if (location != loc) {continue;}
			ier = cg_goto(fn, m_baseId, "Zone_t", m_zoneId, "FlowSolution_t", i, "end");
			bool ok = loadData(physName, magnitude, &value);
			if (! ok) {return false;}
			m_data.push_back(value);
		}
	}
}

bool PostZonePointSeriesDataContainer::loadData(const QString& name, bool magnitude, double* value)
{
	auto zc = zoneDataContainer();
	std::vector<PostCalculatedResult*> calcResults = zc->calculatedResults();
	for (PostCalculatedResult* result : calcResults) {
		if (name == result->name().c_str()) {
			return loadCalculatedData(result, value);
		}
	}
	return loadResultData(name, magnitude, value);
}

bool PostZonePointSeriesDataContainer::loadCalculatedData(PostCalculatedResult* result, double* value)
{
	// calculated value
	std::vector<double> args;
	for (PostCalculatedResultArgument* arg : result->arguments()) {
		double argVal;
		bool ok = loadData(arg->name().c_str(), false, &argVal);
		if (! ok) {return false;}
		args.push_back(argVal);
	}
	*value = result->calculateValue(args);
	return true;
}

bool PostZonePointSeriesDataContainer::loadResultData(const QString& physName, bool magnitude, double* value)
{
	int ier, numArrays;
	ier = cg_narrays(&numArrays);
	if (ier != 0) {return false;}

	*value = 0;

	for (int j = 1; j <= numArrays; ++j) {
		DataType_t datatype;
		int dimension;
		cgsize_t dimVector[3];
		char arrayname[30];

		ier = cg_array_info(j, arrayname, &datatype, &dimension, dimVector);
		if (ier != 0) {return false;}

		QString name(arrayname);
		int dataLen = 1;
		for (int dim = 1; dim <= dimension; ++dim) {
			dataLen = dataLen * dimVector[dim - 1];
		}

		setPointIndex(std::min(m_pointIndex, dataLen - 1));
		std::vector<double> buffer(dataLen);
		ier = cg_array_read_as(j, RealDouble, buffer.data());
		if (magnitude) {
			if (
				name == QString(physName).append("X") ||
				name == QString(physName).append("Y") ||
				name == QString(physName).append("Z")
			) {
				double currVal = buffer[m_pointIndex];
				*value += currVal * currVal;
			}
		} else {
			if (physName == name) {
				*value = buffer[m_pointIndex];
			}
		}
	}
	if (magnitude) {
		*value = std::sqrt(*value);
	}
	return true;
}

PostZoneDataContainer* PostZonePointSeriesDataContainer::zoneDataContainer() const
{
	return postSolutionInfo()->zoneContainer(m_dimension, m_zoneName);
}

void PostZonePointSeriesDataContainer::doLoadFromProjectMainFile(const QDomNode& /*node*/)
{}

void PostZonePointSeriesDataContainer::doSaveToProjectMainFile(QXmlStreamWriter& /*writer*/)
{}
