#include <QFile>
#include <QPointF>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QVector>

#include <geos/geom/Coordinate.h>
#include <geos/geom/CoordinateSequenceFactory.h>
#include <geos/geom/GeometryFactory.h>
#include <geos/geom/LineString.h>
#include <geos/geom/LinearRing.h>
#include <geos/geom/Point.h>

#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataWriter.h>
#include <vtkSmartPointer.h>

#include <iostream>
#include <vector>

/// load lines from CSV file
QVector<QVector<QPointF> > loadLines(const std::string& filename)
{
	QVector<QVector<QPointF> > ret;

	QFile f(filename.c_str());
	bool ok = f.open(QFile::ReadOnly);
	if (! ok) {return ret;}

	QTextStream stream(&f);
	QVector<QPointF> points;

	while (! stream.atEnd()) {
		QString line = stream.readLine();
		QStringList frags = line.split(",");
		if (frags.size() < 2 && points.size() > 0) {
			ret.push_back(points);
			points.clear();
		} else {
			double x = frags[0].toDouble();
			double y = frags[1].toDouble();
			points.push_back(QPointF(x, y));
		}
	}
	ret.push_back(points);

	return ret;
}

/// export the lines into vtk file as vtkPolyData.
/// you can view the data using ParaView etc., that supports VTK file.
void exportLinesToVtk(QVector<QVector<QPointF> >& lines, const std::string& filename)
{
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkCellArray> ca = vtkSmartPointer<vtkCellArray>::New();
	std::vector<vtkIdType> ids;
	vtkIdType vId = 0;

	for (const QVector<QPointF>& line : lines) {
		ids.clear();
		for (const QPointF& p : line) {
			points->InsertNextPoint(p.x(), p.y(), 0);
			ids.push_back(vId++);
		}
		ca->InsertNextCell(ids.size(), ids.data());
	}

	vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
	polyData->SetPoints(points);
	polyData->SetLines(ca);

	vtkSmartPointer<vtkPolyDataWriter> writer = vtkSmartPointer<vtkPolyDataWriter>::New();
	writer->SetFileName(filename.c_str());
	writer->SetInputData(polyData);
	writer->Write();
}

/// export the lines into csv file.
void exportLinesToCsv(QVector<QVector<QPointF> >& lines, const std::string& filename)
{
	QFile f(filename.c_str());
	bool ok = f.open(QFile::WriteOnly);
	if (! ok) {return;}

	QTextStream stream(&f);

	for (int i = 0; i < lines.size(); ++i) {
		if (i != 0) {
			stream << "\r\n";
		}
		const auto& line = lines.at(i);
		for (const QPointF& p : line) {
			stream << p.x() << "," << p.y() << "\r\n";
		}
	}
}

QVector<QVector<QPointF> > unionLines(const QVector<QVector<QPointF> >& lines)
{
	auto factory = geos::geom::GeometryFactory::getDefaultInstance();
	auto cs_factory = factory->getCoordinateSequenceFactory();

	std::vector<geos::geom::Geometry*>* lineStrings = new std::vector<geos::geom::Geometry*>();
	for (const QVector<QPointF>& line : lines) {
		std::vector<geos::geom::Coordinate>* coords = new std::vector<geos::geom::Coordinate>();
		for (QPointF p : line) {
			coords->push_back(geos::geom::Coordinate(p.x(), p.y()));
		}
		auto coordinateSequence = cs_factory->create(coords);
		auto lineString = factory->createLineString(coordinateSequence);
		lineStrings->push_back(lineString);
	}
	auto collection = factory->createGeometryCollection(lineStrings);
	auto geometries = collection->Union();
	geos::geom::MultiLineString* strs = dynamic_cast<geos::geom::MultiLineString*>(geometries.get());

	QVector<QVector<QPointF> > ret;
	for (int i = 0; i < strs->getNumGeometries(); ++i) {
		auto str = dynamic_cast<const geos::geom::LineString*>(strs->getGeometryN(i));
		QVector<QPointF> line;
		for (int j = 0; j < str->getNumPoints(); ++j) {
			geos::geom::Point* p = str->getPointN(j);
			line.push_back(QPointF(p->getX(), p->getY()));
		}
		ret.push_back(line);
	}

	delete collection;

	return ret;
}

void testUnionLines(const std::string& name)
{
	auto lines = loadLines(name + "_input.csv");
	exportLinesToVtk(lines, name + "_input.vtk");

	auto unioned_lines = unionLines(lines);

	exportLinesToCsv(unioned_lines, name + "_output.csv");
	exportLinesToVtk(unioned_lines, name + "_output.vtk");
}

int main(int argc, char* argv[])
{
	testUnionLines("test1");
	testUnionLines("test2");
	testUnionLines("test3");
	return 0;
}
