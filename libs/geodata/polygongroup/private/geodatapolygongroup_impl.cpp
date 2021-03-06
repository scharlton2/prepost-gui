#include "geodatapolygongroup_impl.h"

#include <geoio/polygonutil.h>
#include <geodata/polydatagroup/geodatapolydatagroupcreator.h>
#include <geodata/polygon/geodatapolygon.h>
#include <guicore/pre/base/preprocessorwindowinterface.h>

#include <QAction>

#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkMapper.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkSmartPointer.h>

#include <geos/geom/Envelope.h>
#include <geos/geom/Polygon.h>

#include <algorithm>

GeoDataPolygonGroup::Impl::Impl(GeoDataPolygonGroup* group) :
	m_points {vtkPoints::New()},
	m_edgesPolyData {vtkPolyData::New()},
	m_paintPolyData {vtkPolyData::New()},
	m_edgesActor {vtkActor::New()},
	m_paintActor {vtkActor::New()},
	m_selectedPolygonsEdgesPolyData {vtkPolyData::New()},
	m_selectedPolygonsPointsPolyData {vtkPolyData::New()},
	m_selectedPolygonsEdgesActor {vtkActor::New()},
	m_selectedPolygonsPointsActor {vtkActor::New()},
	m_dummyPolygonForMenu {new GeoDataPolygon(group->parent(), group->creator(), group->gridAttribute())},
	m_group {group}
{
	m_points->SetDataTypeToDouble();

	auto mapper = vtkPolyDataMapper::New();
	m_edgesActor->SetMapper(mapper);
	mapper->SetInputData(m_edgesPolyData);
	mapper->Delete();

	mapper = vtkPolyDataMapper::New();
	m_paintActor->SetMapper(mapper);
	mapper->SetInputData(m_paintPolyData);
	mapper->Delete();

	mapper = vtkPolyDataMapper::New();
	m_selectedPolygonsEdgesActor->SetMapper(mapper);
	mapper->SetInputData(m_selectedPolygonsEdgesPolyData);
	mapper->Delete();

	mapper = vtkPolyDataMapper::New();
	m_selectedPolygonsPointsActor->SetMapper(mapper);
	mapper->SetInputData(m_selectedPolygonsPointsPolyData);
	mapper->Delete();

	m_selectedPolygonsEdgesActor->GetProperty()->SetLineWidth(2);
	m_selectedPolygonsPointsActor->GetProperty()->SetPointSize(5);

	setupDummyPolygonForMenu();
}

GeoDataPolygonGroup::Impl::~Impl()
{
	m_points->Delete();
	m_edgesPolyData->Delete();
	m_paintPolyData->Delete();
	m_edgesActor->Delete();
	m_paintActor->Delete();
	m_selectedPolygonsEdgesPolyData->Delete();
	m_selectedPolygonsPointsPolyData->Delete();
	m_selectedPolygonsEdgesActor->Delete();
	m_selectedPolygonsPointsActor->Delete();

	delete m_dummyPolygonForMenu;
}

void GeoDataPolygonGroup::Impl::setupDummyPolygonForMenu()
{
	m_dummyPolygonForMenu->editNameAndValueAction()->setEnabled(false);
	m_dummyPolygonForMenu->editNameAction()->setEnabled(false);
	m_dummyPolygonForMenu->editValueAction()->setEnabled(false);
	m_dummyPolygonForMenu->addVertexAction()->setEnabled(false);
	m_dummyPolygonForMenu->removeVertexAction()->setEnabled(false);
	m_dummyPolygonForMenu->coordEditAction()->setEnabled(false);
	m_dummyPolygonForMenu->holeModeAction()->setEnabled(false);
	m_dummyPolygonForMenu->deleteAction()->setEnabled(false);
}
