#include "geodatapointgroup.h"
#include "geodatapointgroupcreator.h"
#include "geodatapointgroupcsvexporter.h"
#include "geodatapointgroupcsvimporter.h"
#include "geodatapointgroupshpexporter.h"
#include "geodatapointgroupshpimporter.h"

#include <guicore/pre/base/preprocessorgeodatadataiteminterface.h>

#include <QStandardItem>

GeoDataPointGroupCreator::GeoDataPointGroupCreator(const QString& typeName) :
	GeoDataPolyDataGroupCreator {typeName, tr("Points")}
{
	importers().push_back(new GeoDataPointGroupShpImporter(this));
	importers().push_back(new GeoDataPointGroupCsvImporter(this));
	exporters().push_back(new GeoDataPointGroupShpExporter(this));
	exporters().push_back(new GeoDataPointGroupCsvExporter(this));
}

QString GeoDataPointGroupCreator::name(unsigned int index) const
{
	return QString("pointGroup%1").arg(index);
}

QString GeoDataPointGroupCreator::defaultCaption(unsigned int index) const
{
	return QString(tr("Points%1")).arg(index);
}

bool GeoDataPointGroupCreator::isCreatable() const
{
	return true;
}

GeoData* GeoDataPointGroupCreator::create(ProjectDataItem* parent, SolverDefinitionGridAttribute* condition)
{
	auto g = new GeoDataPointGroup(parent, this, condition);
	PreProcessorGeoDataDataItemInterface* item = dynamic_cast<PreProcessorGeoDataDataItemInterface*>(parent);
	g->setPosition(condition->position());
	g->setDefaultMapper();
	return g;
}

int GeoDataPointGroupCreator::shapeType() const
{
	return SHPT_POINT;
}

QString GeoDataPointGroupCreator::shapeName() const
{
	return tr("point");
}

QString GeoDataPointGroupCreator::shapeNameCamelCase() const
{
	return tr("Point");
}
