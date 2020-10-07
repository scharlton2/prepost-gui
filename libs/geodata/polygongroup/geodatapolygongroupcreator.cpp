#include "geodatapolygongroup.h"
#include "geodatapolygongroupcreator.h"
#include "geodatapolygongroupcsvexporter.h"
#include "geodatapolygongroupshpimporter.h"
#include "geodatapolygongroupshpexporter.h"

#include <shapefil.h>

GeoDataPolygonGroupCreator::GeoDataPolygonGroupCreator(const QString& typeName) :
	GeoDataPolyDataGroupCreator {typeName, tr("Polygon Group")}
{
	importers().push_back(new GeoDataPolygonGroupShpImporter(this));
	exporters().push_back(new GeoDataPolygonGroupShpExporter(this));
	exporters().push_back(new GeoDataPolygonGroupCsvExporter(this));
}

QString GeoDataPolygonGroupCreator::name(unsigned int index) const
{
	return QString("polygonGroup%1").arg(index);
}

QString GeoDataPolygonGroupCreator::defaultCaption(unsigned int index) const
{
	return QString(tr("Polygon Group%1")).arg(index);
}

bool GeoDataPolygonGroupCreator::isCreatable() const
{
	return true;
}

GeoData* GeoDataPolygonGroupCreator::create(ProjectDataItem* parent, SolverDefinitionGridAttribute* condition)
{
	auto g = new GeoDataPolygonGroup(parent, this, condition);
	g->setPosition(condition->position());
	g->setDefaultMapper();
	return g;
}

int GeoDataPolygonGroupCreator::shapeType() const
{
	return SHPT_POLYGON;
}

QString GeoDataPolygonGroupCreator::shapeName() const
{
	return tr("polygon");
}

QString GeoDataPolygonGroupCreator::shapeNameCamelCase() const
{
	return tr("Polygon");
}
