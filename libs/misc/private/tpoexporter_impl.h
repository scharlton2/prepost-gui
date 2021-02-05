#ifndef TPOEXPORTER_IMPL_H
#define TPOEXPORTER_IMPL_H

#include "../tpoexporter.h"

#include <QPointF>

class QFile;
class QTextStream;
class QWidget;

class TpoExporter::Impl
{
public:
	Impl();
	~Impl();

	QPointF m_offset;

	QFile* m_file;
	QTextStream* m_stream;
	int m_xPrecision;
	int m_yPrecision;
	int m_zPrecision;

	QWidget* m_widget;
};

#endif // TPOEXPORTER_IMPL_H