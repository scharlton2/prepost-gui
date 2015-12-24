#ifndef GEODATAPOLYGONCREATOR_H
#define GEODATAPOLYGONCREATOR_H

#include "gd_polygon_global.h"
#include <guicore/pre/geodata/geodatacreator.h>

class GD_POLYGON_EXPORT GeoDataPolygonCreator : public GeoDataCreator
{
	Q_OBJECT

public:
	GeoDataPolygonCreator();

	QString name(unsigned int index) override;
	QString defaultCaption(unsigned int index) override;

	bool isCreatable() const override;

	GeoData* create(ProjectDataItem* parent, SolverDefinitionGridAttribute* condition) override;
};

#endif // GEODATAPOLYGONCREATOR_H
