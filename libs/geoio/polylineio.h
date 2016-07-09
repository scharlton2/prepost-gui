#ifndef POLYLINEIO_H
#define POLYLINEIO_H

#include "geoio_global.h"

#include <QVector>

class QPointF;
class QWidget;

class GEOIODLL_EXPORT PolylineIO
{
public:
	static QVector<QPointF> importData(QWidget* w);
	static void exportData(const QVector<QPointF>& polyline, QWidget* w);

private:
	PolylineIO();
};

#endif // POLYLINEIO_H
