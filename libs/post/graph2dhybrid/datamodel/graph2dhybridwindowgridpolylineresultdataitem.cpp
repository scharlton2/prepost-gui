#include "../../../geodata/polyline/geodatapolyline.h"
#include "../../../geodata/polyline/geodatapolylineimplpolyline.h"
#include "../graph2dhybridwindow.h"
#include "../graph2dhybridwindowcontrolwidget.h"
#include "../graph2dhybridwindowresultsetting.h"
#include "../graph2dhybridwindowview.h"
#include "graph2dhybridwindowgridpolylineresultdataitem.h"
#include "graph2dhybridwindowresultcopydataitem.h"
#include "graph2dhybridwindowresultdataitem.h"
#include "graph2dhybridwindowresultgroupdataitem.h"

#include <guicore/postcontainer/posttimesteps.h>
#include <guicore/postcontainer/postzonedatacontainer.h>
#include <misc/stringtool.h>
#include <misc/stringtool.h>

#include <QPen>
#include <QStandardItem>
#include <QVector2D>
#include <QVector3D>


#include <vtkCellData.h>
#include <vtkCutter.h>
#include <vtkDoubleArray.h>
#include <vtkExtractGrid.h>
#include <vtkMath.h>
#include <vtkPlane.h>
#include <vtkPointData.h>
#include <vtkSmartPointer.h>
#include <vtkStructuredGrid.h>
#include <vtkUnstructuredGrid.h>

#include <cmath>
#include <qwt_plot_curve.h>

Graph2dHybridWindowGridPolylineResultDataItem::Graph2dHybridWindowGridPolylineResultDataItem(const Graph2dHybridWindowResultSetting::Setting& setting, int index, Graph2dWindowDataItem* parent)
	: Graph2dHybridWindowResultDataItem(setting.name(), index, setting, parent)
{
	m_physVal = setting.name();

	Q_ASSERT(dataModel());
	const Graph2dHybridWindowResultSetting& s = dataModel()->setting();
	Q_ASSERT(s.xAxisMode() == Graph2dHybridWindowResultSetting::xaPolyline);
	const GeoDataPolyLine *line = s.targetPolyLine();
	///Q_ASSERT(line);

	connect(line, SIGNAL(modified()), dataModel(), SLOT(applySettingsSlot()));
}

Graph2dHybridWindowGridPolylineResultDataItem::~Graph2dHybridWindowGridPolylineResultDataItem()
{
}

void Graph2dHybridWindowGridPolylineResultDataItem::doLoadFromProjectMainFile(const QDomNode& /*node*/)
{

}

void Graph2dHybridWindowGridPolylineResultDataItem::doSaveToProjectMainFile(QXmlStreamWriter& /*writer*/)
{

}

//#include <QMessageBox>


void Graph2dHybridWindowGridPolylineResultDataItem::updateValues(int /*fn*/)
{
	m_xValues.clear();
	m_yValues.clear();

	const Graph2dHybridWindowResultSetting& s = dataModel()->setting();
	Graph2dHybridWindowResultSetting::DataTypeInfo* info = s.targetDataTypeInfo();

	PostSolutionInfo* postInfo = dataModel()->postSolutionInfo();
	PostZoneDataContainer* cont = postInfo->zoneContainer(info->dimension, info->zoneName);
	if (cont == 0) {return;}

	//vtkStructuredGrid* grid = vtkStructuredGrid::SafeDownCast(cont->data());
	////{{
	//vtkUnstructuredGrid* ugrid = vtkUnstructuredGrid::SafeDownCast(cont->data());
	////}}

	vtkPointSet* grid = vtkPointSet::SafeDownCast(cont->data());

	if (info->gridLocation == Vertex) {
		//if (grid) updateValuesVertex(grid);
		//if (ugrid) updateValuesVertex(ugrid);
		updateValuesVertex(grid);
	}
	else if (info->gridLocation == CellCenter) {
		//Q_ASSERT(false);
		updateValuesCellCenter(grid);
	} else {
		Q_ASSERT(false);   //   Unhandled GridLocation_t
	}
}

//void Graph2dHybridWindowGridPolylineResultDataItem::updateValuesVertex(vtkStructuredGrid* grid)
void Graph2dHybridWindowGridPolylineResultDataItem::updateValuesVertex(vtkPointSet* grid)
{
	vtkDataArray* da = grid->GetPointData()->GetArray(iRIC::toStr(m_physVal).c_str());
	if (da == nullptr) {
		// no data found.
		return;
	}

	const Graph2dHybridWindowResultSetting& s = dataModel()->setting();

	const GeoDataPolyLine *line = s.targetPolyLine();
	if (line == nullptr) { return; }

	GeoDataPolyLineImplPolyLine* impl = line->polyLine();

	std::vector<QPointF>& pts = impl->polyLine();

	double origin[3];
	std::map<double, std::vector<double> > amap;
	double prev_end_pt[3];

	vtkSmartPointer<vtkPlane> plane = vtkSmartPointer<vtkPlane>::New();

	vtkSmartPointer<vtkCutter> cutter = vtkSmartPointer<vtkCutter>::New();
	cutter->SetInputData(grid);

	for (int idx = 0; idx < pts.size() - 1; ++idx) {
		// create plane from point[n] -> point[n+1]

		double a[3] = { pts[idx].x(), pts[idx].y(), 0. };
		double b[3] = { pts[idx + 1].x(), pts[idx + 1].y(), 0. };

		double ab[3] = { (b[0] - a[0]), (b[1] - a[1]), 0. };
		double ac[3] = { 0., 0., 1. };
		double cross[3];

		vtkMath::Cross(ab, ac, cross);

		plane->SetOrigin(a);
		plane->SetNormal(cross);

		cutter->SetCutFunction(plane);
		cutter->Update();

		vtkDataArray *da = cutter->GetOutput()->GetPointData()->GetArray(iRIC::toStr(m_physVal).c_str());

		double max[3];
		double min[3];

		min[0] = std::min(a[0], b[0]);
		max[0] = std::max(a[0], b[0]);
		min[1] = std::min(a[1], b[1]);
		max[1] = std::max(a[1], b[1]);

		origin[0] = pts[idx].x();
		origin[1] = pts[idx].y();

		amap.clear();
		int numT = da->GetNumberOfTuples();
		for (int i = 0; i < numT; ++i) {
			double p[3];
			cutter->GetOutput()->GetPoint(i, p);

			// y value
			double value = 0;
			if (da->GetNumberOfComponents() == 1) {
				value = da->GetTuple1(i);
			}
			else if (da->GetNumberOfComponents() == 3) {
				double* v;
				v = da->GetTuple3(i);
				value = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
			}

			// x value
			if ((min[0] <= p[0] && p[0] <= max[0]) && (min[1] <= p[1] && p[1] <= max[1])) {
				std::vector<double> v;
				v.push_back(p[0]);
				v.push_back(p[1]);
				v.push_back(value);
				QVector3D d0(origin[0] - p[0], origin[1] - p[1], 0.0);
				amap.insert(std::pair<double, std::vector<double> >(d0.length(), v));
			}
		}
		double offset = 0;
		if (amap.size() == 0) continue;
		if (m_xValues.size() > 0) {
			double start_pt[3];
			start_pt[0] = (*amap.cbegin()).second[0];
			start_pt[1] = (*amap.cbegin()).second[1];
			QVector3D d(prev_end_pt[0] - start_pt[0], prev_end_pt[1] - start_pt[1], 0.0);
			offset = m_xValues.last() + d.length();
		}
		double distance = 0;
		if (m_xValues.size() > 0) distance = m_xValues.last();
		for (const auto& pr : amap) {
			distance = pr.first - amap.cbegin()->first;
			m_xValues.push_back(distance + offset);
			m_yValues.push_back(pr.second[2]);
		}
		prev_end_pt[0] = amap.crbegin()->second[0];
		prev_end_pt[1] = amap.crbegin()->second[1];
	}
}


//void Graph2dHybridWindowGridPolylineResultDataItem::updateValuesVertex(vtkPointSet* grid)
//{
//	vtkDataArray* da = grid->GetPointData()->GetArray(iRIC::toStr(m_physVal).c_str());
//	if (da == nullptr) {
//		// no data found.
//		return;
//	}
//
//	const Graph2dHybridWindowResultSetting& s = dataModel()->setting();
//
//	const GeoDataPolyLine *line = s.targetPolyLine();
//	if (line == nullptr) { return; }
//
//	GeoDataPolyLineImplPolyLine* impl = line->polyLine();
//
//	std::vector<QPointF>& pts = impl->polyLine();
//
//	double origin[3];
//	std::map<double, std::vector<double> > amap;
//	double prev_end_pt[3];
//
//	vtkSmartPointer<vtkPlane> plane = vtkSmartPointer<vtkPlane>::New();
//
//	vtkSmartPointer<vtkCutter> cutter = vtkSmartPointer<vtkCutter>::New();
//	cutter->SetInputData(grid);
//
//	for (int idx = 0; idx < pts.size() - 1; ++idx) {
//		// create plane from point[n] -> point[n+1]
//
//		double a[3] = { pts[idx].x(), pts[idx].y(), 0. };
//		double b[3] = { pts[idx + 1].x(), pts[idx + 1].y(), 0. };
//
//		double ab[3] = { (b[0] - a[0]), (b[1] - a[1]), 0. };
//		double ac[3] = { 0., 0., 1. };
//		double cross[3];
//
//		vtkMath::Cross(ab, ac, cross);
//
//		plane->SetOrigin(a);
//		plane->SetNormal(cross);
//
//		cutter->SetCutFunction(plane);
//		cutter->Update();
//
//		vtkDataArray *da = cutter->GetOutput()->GetPointData()->GetArray(iRIC::toStr(m_physVal).c_str());
//
//		double max[3];
//		double min[3];
//
//		min[0] = std::min(a[0], b[0]);
//		max[0] = std::max(a[0], b[0]);
//		min[1] = std::min(a[1], b[1]);
//		max[1] = std::max(a[1], b[1]);
//
//		origin[0] = pts[idx].x();
//		origin[1] = pts[idx].y();
//
//		amap.clear();
//		int numT = da->GetNumberOfTuples();
//		for (int i = 0; i < numT; ++i) {
//			double p[3];
//			cutter->GetOutput()->GetPoint(i, p);
//
//			// y value
//			double value = 0;
//			if (da->GetNumberOfComponents() == 1) {
//				value = da->GetTuple1(i);
//			}
//			else if (da->GetNumberOfComponents() == 3) {
//				double* v;
//				v = da->GetTuple3(i);
//				value = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
//			}
//
//			// x value
//			if ((min[0] <= p[0] && p[0] <= max[0]) && (min[1] <= p[1] && p[1] <= max[1])) {
//				std::vector<double> v;
//				v.push_back(p[0]);
//				v.push_back(p[1]);
//				v.push_back(value);
//				QVector3D d0(origin[0] - p[0], origin[1] - p[1], 0.0);
//				amap.insert(std::pair<double, std::vector<double> >(d0.length(), v));
//			}
//		}
//		double offset = 0;
//		if (amap.size() == 0) continue;
//		if (m_xValues.size() > 0) {
//			double start_pt[3];
//			start_pt[0] = (*amap.cbegin()).second[0];
//			start_pt[1] = (*amap.cbegin()).second[1];
//			QVector3D d(prev_end_pt[0] - start_pt[0], prev_end_pt[1] - start_pt[1], 0.0);
//			offset = m_xValues.last() + d.length();
//		}
//		double distance = 0;
//		if (m_xValues.size() > 0) distance = m_xValues.last();
//		for (const auto& pr : amap) {
//			distance = pr.first - amap.cbegin()->first;
//			m_xValues.push_back(distance + offset);
//			m_yValues.push_back(pr.second[2]);
//		}
//		prev_end_pt[0] = amap.crbegin()->second[0];
//		prev_end_pt[1] = amap.crbegin()->second[1];
//	}
//}


#include <sstream>

void Graph2dHybridWindowGridPolylineResultDataItem::updateValuesCellCenter(vtkPointSet* grid)
{
	vtkDataArray* da = grid->GetCellData()->GetArray(iRIC::toStr(m_physVal).c_str());
	if (da == nullptr) {
		// no data found.
		return;
	}

	const Graph2dHybridWindowResultSetting& s = dataModel()->setting();

	const GeoDataPolyLine *line = s.targetPolyLine();
	if (line == nullptr) { return; }

	GeoDataPolyLineImplPolyLine* impl = line->polyLine();

	std::vector<QPointF>& pts = impl->polyLine();
	///[[
	std::ostringstream oss3;
	oss3 << "pts" << std::endl;
	oss3 << std::setprecision(14) << std::fixed;
	for (int i = 0; i < pts.size(); ++i) {
		oss3 << "i = " << i << ", " << pts[i].x() << ", " << pts[i].y() << std::endl;
	}
	qDebug("%s", oss3.str().c_str());
	///]]


	double origin[3];
	std::map<double, std::vector<double> > amap;
	double prev_end_pt[3];

	vtkSmartPointer<vtkPlane> plane = vtkSmartPointer<vtkPlane>::New();

	vtkSmartPointer<vtkCutter> cutter = vtkSmartPointer<vtkCutter>::New();
	cutter->SetInputData(grid);

	for (int idx = 0; idx < pts.size() - 1; ++idx) {
		// create plane from point[n] -> point[n+1]

		double a[3] = { pts[idx].x(), pts[idx].y(), 0. };
		double b[3] = { pts[idx + 1].x(), pts[idx + 1].y(), 0. };

		double ab[3] = { (b[0] - a[0]), (b[1] - a[1]), 0. };
		double ac[3] = { 0., 0., 1. };
		double cross[3];

		vtkMath::Cross(ab, ac, cross);

		plane->SetOrigin(a);
		plane->SetNormal(cross);

		cutter->SetCutFunction(plane);
		cutter->Update();

		vtkDataArray *da = cutter->GetOutput()->GetCellData()->GetArray(iRIC::toStr(m_physVal).c_str());
		//{{
		//cutter->GetOutput()->GetCell();
		//}}

		double max[3];
		double min[3];

		min[0] = std::min(a[0], b[0]);
		max[0] = std::max(a[0], b[0]);
		min[1] = std::min(a[1], b[1]);
		max[1] = std::max(a[1], b[1]);

		//[[
		std::ostringstream oss33;
		oss33 << std::setprecision(14) << std::fixed;
		oss33 << "min[0] = " << min[0] << std::endl;
		oss33 << "max[0] = " << max[0] << std::endl;
		oss33 << "min[1] = " << min[1] << std::endl;
		oss33 << "max[1] = " << max[1] << std::endl;
		qDebug("%s", oss33.str().c_str());
		//]]

		origin[0] = pts[idx].x();
		origin[1] = pts[idx].y();

		amap.clear();
		int numT = da->GetNumberOfTuples();
		int npts = cutter->GetOutput()->GetNumberOfPoints();
		Q_ASSERT(true || cutter->GetOutput()->GetNumberOfPoints() - 1 == numT);
		//{{
		std::ostringstream oss2;
		oss2 << std::setprecision(14) << std::fixed;
		oss2 << "numT = " << numT << " npts = " << npts << std::endl;
		//}}
		for (int i = 0; i < numT; ++i) {
			double p[3];
			cutter->GetOutput()->GetPoint(i, p);

			// y value
			double value = 0;
			if (da->GetNumberOfComponents() == 1) {
				value = da->GetTuple1(i);
			}
			else if (da->GetNumberOfComponents() == 3) {
				double* v;
				v = da->GetTuple3(i);
				value = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
			}

			// x value
			//if ((min[0] <= p[0] && p[0] <= max[0]) && (min[1] <= p[1] && p[1] <= max[1]))
			{
				std::vector<double> v;
				v.push_back(p[0]);
				v.push_back(p[1]);
				v.push_back(value);
				QVector3D d0(origin[0] - p[0], origin[1] - p[1], 0.0);
				//amap.insert(std::pair<double, std::vector<double> >(d0.length(), v));
				//{{
				oss2 << "i = " << i << " distance = " << d0.length() << " p = " << p[0] << ", " << p[1] << ", " << p[2] << ", value = " << value;
				if ((min[0] <= p[0] && p[0] <= max[0]) && (min[1] <= p[1] && p[1] <= max[1])) {
					amap.insert(std::pair<double, std::vector<double> >(d0.length(), v));
					oss2 << "  ADDED_TO_MAP";
				}
				//}}
			}
			//{{
			oss2 << std::endl;
			//}}
		}
		//{{
		qDebug("%s", oss2.str().c_str());
		//}}
		double offset = 0;
		if (amap.size() == 0) continue;
		if (m_xValues.size() > 0) {
			double start_pt[3];
			start_pt[0] = (*amap.cbegin()).second[0];
			start_pt[1] = (*amap.cbegin()).second[1];
			QVector3D d(prev_end_pt[0] - start_pt[0], prev_end_pt[1] - start_pt[1], 0.0);
			offset = m_xValues.last() + d.length();
		}
		double distance = 0;
		if (m_xValues.size() > 0) distance = m_xValues.last();
		for (const auto& pr : amap) {
			distance = pr.first - amap.cbegin()->first;
			m_xValues.push_back(distance + offset);
			m_yValues.push_back(pr.second[2]);
		}
		/*
		std::map<double, std::vector<double> >::const_iterator cit = amap.cbegin();
		for (; cit != amap.cend(); ++cit) {
			std::map<double, std::vector<double> >::const_iterator next = cit;
			++next;
			distance = ((*next).first - (*cit).first) / 2;
			m_xValues.push_back(distance + offset);
			m_yValues.push_back((*cit).second[2]);
		}
		*/
		//{{
		std::ostringstream oss;
		oss << std::setprecision(14) << std::fixed;
		Q_ASSERT(m_xValues.size() == m_yValues.size());
		oss << "m_xValues.size() = " << m_xValues.size() << " m_yValues.size() = " << m_yValues.size() << std::endl;
		for (int i = 0; i < m_xValues.size(); ++i) {
			oss << "i = " << i << " x = " << m_xValues[i] << ", y = " << m_yValues[i] << std::endl;
		}
		qDebug("%s", oss.str().c_str());
		//}}

		prev_end_pt[0] = amap.crbegin()->second[0];
		prev_end_pt[1] = amap.crbegin()->second[1];
	}

}


Graph2dHybridWindowResultCopyDataItem* Graph2dHybridWindowGridPolylineResultDataItem::copy(Graph2dHybridWindowResultCopyGroupDataItem* p)
{
	Graph2dHybridWindowResultCopyDataItem* ret = Graph2dHybridWindowResultDataItem::copy(p);

	const Graph2dHybridWindowResultSetting& s = dataModel()->setting();
	Graph2dHybridWindowResultSetting::DataTypeInfo* info = s.targetDataTypeInfo();

	PostSolutionInfo* postInfo = dataModel()->postSolutionInfo();
	Graph2dHybridWindow* w = dynamic_cast<Graph2dHybridWindow*>(dataModel()->mainWindow());
	Graph2dHybridWindowControlWidget* c = w->controlWidget();

	int currentStep = postInfo->currentStep();
	const QList<double>& timesteps = postInfo->timeSteps()->timesteps();
	double time;
	if (timesteps.count() == 0) {
		time = 0;
	} else {
		if (currentStep < timesteps.count()) {
			time = timesteps.at(currentStep);
		} else {
			time = 0;
		}
	}

	QStringList args;
	args.append(m_standardItem->text());
	args.append(QString::number(time));
	if (info->dataType == Graph2dHybridWindowResultSetting::dtDim1DStructured) {
		ret->setId(Graph2dHybridWindowResultCopyDataItem::idt1D, args);
	} else if (info->dataType == Graph2dHybridWindowResultSetting::dtDim2DStructured) {
		if (s.xAxisMode() == Graph2dHybridWindowResultSetting::xaI) {
			args.append(QString::number(c->jValue() + 1));
			ret->setId(Graph2dHybridWindowResultCopyDataItem::idtI2D, args);
		} else {
			args.append(QString::number(c->iValue() + 1));
			ret->setId(Graph2dHybridWindowResultCopyDataItem::idtJ2D, args);
		}
	} else if (info->dataType == Graph2dHybridWindowResultSetting::dtDim3DStructured) {
		if (s.xAxisMode() == Graph2dHybridWindowResultSetting::xaI) {
			args.append(QString::number(c->jValue() + 1));
			args.append(QString::number(c->kValue() + 1));
			ret->setId(Graph2dHybridWindowResultCopyDataItem::idtI3D, args);
		} else if (s.xAxisMode() == Graph2dHybridWindowResultSetting::xaJ) {
			args.append(QString::number(c->iValue() + 1));
			args.append(QString::number(c->kValue() + 1));
			ret->setId(Graph2dHybridWindowResultCopyDataItem::idtJ3D, args);
		} else {
			args.append(QString::number(c->iValue() + 1));
			args.append(QString::number(c->jValue() + 1));
			ret->setId(Graph2dHybridWindowResultCopyDataItem::idtK3D, args);
		}
	}
	return ret;
}
