#include "arbitraryhwmpreprocessorviewhelper.h"
#include "../points/pointsgraphicssetting.h"

#include <QColor>

ArbitraryHWMPreProcessorViewHelper::ArbitraryHWMPreProcessorViewHelper(DataItemView* v) :
	PointsPreProcessorViewHelper {v}
{}

void ArbitraryHWMPreProcessorViewHelper::draw(QPainter* painter) const
{
	auto setting = PointsGraphicsSetting::waterElevationPointsSetting;
	drawRects(STD_SIZE, Qt::gray, setting.transparency, painter);
}