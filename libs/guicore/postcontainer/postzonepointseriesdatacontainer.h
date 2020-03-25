#ifndef POSTZONEPOINTSERIESDATACONTAINER_H
#define POSTZONEPOINTSERIESDATACONTAINER_H

#include "../guicore_global.h"
#include "postsolutioninfo.h"
#include "postseriesdatacontainer.h"
#include <QString>
#include <QList>
#include <cgnslib.h>

#if CGNS_VERSION < 3100
#define cgsize_t int
#endif

class PostCalculatedResult;
class SolverDefinitionGridType;
class ScalarsToColorsContainer;
class ScalarsToColorsEditDialog;

class GUICOREDLL_EXPORT PostZonePointSeriesDataContainer : public PostSeriesDataContainer
{

public:
	PostZonePointSeriesDataContainer(PostSolutionInfo::Dimension dim, const std::string& zoneName, const QString& pName, int pointIndex, GridLocation_t gridLocation, PostSolutionInfo* sinfo);
	const QList<double>& data() const;

	void update(const int fn);
	const std::string& zoneName() const;
	/// Caption is the region name in pre-processor.
	/// Currently, zone name is used instead, temporally.
	QString caption() const;

	int pointIndex() const;
	void setPointIndex(int index);

	GridLocation_t gridLocation() const;
	void setGridLocation(GridLocation_t location);

private:
	bool setZoneId(const int fn);

	bool loadData(const int fn) override;
	bool loadData(const int fn, GridLocation_t location);
	bool loadData(const QString& name, bool magnitude, double* value);
	bool loadCalculatedData(PostCalculatedResult* result, double* value);
	bool loadResultData(const QString& physName, bool magnitude, double* value);

	PostZoneDataContainer* zoneDataContainer() const;

	void doLoadFromProjectMainFile(const QDomNode& node) override;
	void doSaveToProjectMainFile(QXmlStreamWriter& writer) override;

	QList<double> m_data;
	std::string m_zoneName;
	int m_zoneId;
	QString m_physName;
	int m_pointIndex;
	GridLocation_t m_gridLocation;
	cgsize_t m_sizes[9];
};

#endif // POSTZONEPOINTSERIESDATACONTAINER_H
