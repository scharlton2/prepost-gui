#include "../misc/cgnsfileopener.h"
#include "../project/projectcgnsfile.h"
#include "../project/projectdata.h"
#include "../project/projectmainfile.h"
#include "postsolutioninfo.h"
#include "posttimesteps.h"
#include "postzonepointseriesdatacontainer.h"

#include <misc/stringtool.h>

#include <QRegExp>

#include <cgnslib.h>
#include <cmath>

PostZonePointSeriesDataContainer::PostZonePointSeriesDataContainer(PostSolutionInfo::Dimension dim, const std::string& zoneName, const QString& pName, int pointIndex, GridLocation_t gridLocation, ProjectDataItem* parent) :
	PostSeriesDataContainer(dim, parent),
	m_zoneName (zoneName),
	m_zoneId {0},
	m_physName {pName},
	m_pointIndex {pointIndex},
	m_gridLocation {gridLocation}
{}

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

double PostZonePointSeriesDataContainer::loadData(const QString& physName, bool magnitude)
{
	int ier, numArrays;
	ier = cg_narrays(&numArrays);
	if (ier != 0) {return false;}

	double value = 0;

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
				value += currVal * currVal;
			}
		} else {
			if (physName == name) {
				value = buffer[m_pointIndex];
			}
		}
	}
	if (magnitude) {
		value = std::sqrt(value);
	}
	return value;
}

bool PostZonePointSeriesDataContainer::loadData(const int fn, GridLocation_t location)
{
	bool ret;
	int ier;
	int numSols;
	char solname[32];
	GridLocation_t loc;

	ret = setZoneId(fn);
	if (! ret) {return false;}

	QRegExp rx("^(.+) \\(magnitude\\)$");
	bool magnitude = (rx.indexIn(m_physName) != -1);
	QString physName = m_physName;
	if (magnitude) {
		// shortname
		physName = rx.cap(1);
	}
	m_data.clear();

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
				double value = loadData(physName, magnitude);
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
			double value = loadData(physName, magnitude);
			m_data.push_back(value);
		}
	}
	return true;
}

bool PostZonePointSeriesDataContainer::loadData(const int fn)
{
	return loadData(fn, m_gridLocation);
}
