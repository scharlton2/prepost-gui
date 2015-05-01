#include "datamodel/post2dwindowcellflaggroupdataitem.h"
#include "datamodel/post2dwindowgridshapedataitem.h"
#include "datamodel/post2dwindowgridtypedataitem.h"
#include "datamodel/post2dwindowmeasureddatatopdataitem.h"
#include "datamodel/post2dwindownodescalargroupdataitem.h"
#include "datamodel/post2dwindownodevectorarrowgroupdataitem.h"
#include "datamodel/post2dwindownodevectorparticlegroupdataitem.h"
#include "datamodel/post2dwindownodevectorstreamlinegroupdataitem.h"
#include "datamodel/post2dwindowrootdataitem.h"
#include "datamodel/post2dwindowzonedataitem.h"
#include "post2dwindow.h"
#include "post2dwindowdatamodel.h"
#include "post2dwindowgraphicsview.h"

#include <guibase/itemselectingdialog.h>
#include <guibase/objectbrowserview.h>
#include <guicore/measureddata/measureddatafiledataitem.h>
#include <guicore/measureddata/measureddatapointgroupdataitem.h>
#include <guicore/measureddata/measureddatavectorgroupdataitem.h>
#include <guicore/post/postzoneselectingdialog.h>
#include <guicore/postcontainer/postsolutioninfo.h>
#include <guicore/project/projectdata.h>
#include <guicore/project/projectmainfile.h>
#include <postbase/time/posttimedataitem.h>
#include <postbase/title/posttitledataitem.h>

#include <QGraphicsItemGroup>
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>

#include <cmath>

#define _USE_MATH_DEFINES



Post2dWindowDataModel::Post2dWindowDataModel(Post2dWindow* w, ProjectDataItem* parent)
	: Graphics2DWindowDataModel(w, parent)
{
	m_objectBrowserView = nullptr;
	init();
}

Post2dWindowDataModel::~Post2dWindowDataModel()
{
	m_objectBrowserView->blockSignals(true);
	delete m_rootDataItem;
	m_objectBrowserView->blockSignals(false);
}

void Post2dWindowDataModel::init()
{
	// Discard the old data.
	// We do not need the next line, because the m_rootDataItem
	// is deleted automatically when the last projectdata is deleted.
	// if (m_rootDataItem != nullptr){delete m_rootDataItem;}
	// build new data.
	m_graphicsView = new Post2dWindowGraphicsView(dynamic_cast<QWidget*>(parent()));
	connect(m_graphicsView, SIGNAL(worldPositionChangedForStatusBar(QVector2D)), mainWindow(), SIGNAL(worldPositionChangedForStatusBar(QVector2D)));

	// setup the basic itemModel structure.
	Post2dWindowRootDataItem* root = new Post2dWindowRootDataItem(dynamic_cast<Post2dWindow*>(m_mainWindow), this);
	m_rootDataItem = root;
	root->setZDepthRange(m_dataRange);
	root->setupStandardModel(m_itemModel);
	connect(m_itemModel, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(handleObjectBrowserChange(QStandardItem*)));

	m_graphicsView->setActiveDataItem(root);
	m_graphicsView->setModel(this);
	fit();
}

Post2dWindowGraphicsView* Post2dWindowDataModel::graphicsView() const
{
	return dynamic_cast<Post2dWindowGraphicsView*>(m_graphicsView);
}

PostSolutionInfo* Post2dWindowDataModel::postSolutionInfo()
{
	return projectData()->mainfile()->postSolutionInfo();
}

void Post2dWindowDataModel::gridShapeSetting()
{
	Post2dWindowZoneDataItem* zItem = getZoneDataItem();
	if (zItem == nullptr) {return;}
	Post2dWindowGridShapeDataItem* item = zItem->gridShapeDataItem();
	if (item == nullptr) {return;}
	item->showPropertyDialog();
}

void Post2dWindowDataModel::contourSetting()
{
	Post2dWindowZoneDataItem* zItem = getZoneDataItem();
	if (zItem == nullptr) {return;}
	Post2dWindowNodeScalarGroupDataItem* item = zItem->scalarGroupDataItem();
	if (item == nullptr) {
		QMessageBox::warning(mainWindow(),tr("Warning"), tr("Contour setting is not available, because this result does not contain scalar values."));
		return;
	}
	item->showPropertyDialog();
}

void Post2dWindowDataModel::vectorSetting()
{
	Post2dWindowZoneDataItem* zItem = getZoneDataItem();
	if (zItem == nullptr) {return;}
	Post2dWindowNodeVectorArrowGroupDataItem* item = zItem->arrowGroupDataItem();
	if (item == nullptr) {
		QMessageBox::warning(mainWindow(),tr("Warning"), tr("Arrow setting is not available, because this result does not contain vector values."));
		return;
	}
	item->showPropertyDialog();
}

void Post2dWindowDataModel::streamlineSetting()
{
	Post2dWindowZoneDataItem* zItem = getZoneDataItem();
	if (zItem == nullptr) {return;}
	Post2dWindowNodeVectorStreamlineGroupDataItem* item = zItem->streamlineDataItem();
	if (item == nullptr) {
		QMessageBox::warning(mainWindow(),tr("Warning"), tr("Streamline setting is not available, because this result does not contain vector values."));
		return;
	}
	item->showPropertyDialog();
}

void Post2dWindowDataModel::particleSetting()
{
	Post2dWindowZoneDataItem* zItem = getZoneDataItem();
	if (zItem == nullptr) {return;}
	Post2dWindowNodeVectorParticleGroupDataItem* item = zItem->particleDataItem();
	if (item == nullptr) {
		QMessageBox::warning(mainWindow(),tr("Warning"), tr("Particle setting is not available, because this result does not contain vector values."));
		return;
	}
	item->showPropertyDialog();
}

void Post2dWindowDataModel::cellFlagSetting()
{
	Post2dWindowZoneDataItem* zItem = getZoneDataItem();
	if (zItem == nullptr) {return;}
	Post2dWindowCellFlagGroupDataItem* item = zItem->cellFlagGroupDataItem();
	item->showPropertyDialog();
}

Post2dWindowZoneDataItem* Post2dWindowDataModel::getZoneDataItem()
{
	GraphicsWindowDataItem* item = m_selectedItem;
	while (item != nullptr) {
		Post2dWindowZoneDataItem* zitem = dynamic_cast<Post2dWindowZoneDataItem*>(item);
		// zone item found!
		if (zitem != nullptr) {return zitem;}
		// try parent item.
		item = dynamic_cast<GraphicsWindowDataItem*>(item->parent());
		if (dynamic_cast<GraphicsWindowRootDataItem*>(item) != nullptr) {
			// reached to root node.
			break;
		}
	}
	// no appropriate zonedatatem found.
	PostSolutionInfo* info = postSolutionInfo();
	QList<PostZoneDataContainer*> containers = info->zoneContainers2D();
	Post2dWindowZoneDataItem* zitem;
	if (containers.count() == 0) {
		// No zone container exists.
		return nullptr;
	} else if (containers.count() > 1) {
		// Multiple zone containers found.
		PostZoneSelectingDialog dialog(mainWindow());
		dialog.setContainers(containers);
		int ret = dialog.exec();
		if (ret != QDialog::Accepted) {return nullptr;}
		QString gridType = dialog.gridTypeName();
		QString zone = dialog.zoneName();
		Post2dWindowRootDataItem* root = dynamic_cast<Post2dWindowRootDataItem*>(m_rootDataItem);
		Post2dWindowGridTypeDataItem* gt = root->gridTypeDataItem(gridType);
		zitem = gt->zoneData(zone);
		return zitem;
	} else {
		Post2dWindowRootDataItem* root = dynamic_cast<Post2dWindowRootDataItem*>(m_rootDataItem);
		QList<Post2dWindowGridTypeDataItem*> list = root->gridTypeDataItems();
		Post2dWindowGridTypeDataItem* gt = list.at(0);
		QList<Post2dWindowZoneDataItem*> zonelist = gt->zoneDatas();
		zitem = zonelist.at(0);
		return zitem;
	}
}

MeasuredDataFileDataItem* Post2dWindowDataModel::getMeasuredDataFileDataItem()
{
	GraphicsWindowDataItem* item = m_selectedItem;
	while (item != nullptr) {
		MeasuredDataFileDataItem* mitem = dynamic_cast<MeasuredDataFileDataItem*>(item);
		if (mitem != nullptr) {return mitem;}
		// try parent item.
		item = dynamic_cast<GraphicsWindowDataItem*>(item->parent());
		if (dynamic_cast<GraphicsWindowRootDataItem*>(item) != nullptr) {
			// reached to root node.
			break;
		}
	}
	Post2dWindowRootDataItem* root = dynamic_cast<Post2dWindowRootDataItem*>(m_rootDataItem);
	Post2dWindowMeasuredDataTopDataItem* mdItem = root->measuredDataTopDataItem();
	if (mdItem->childItems().count() == 1) {
		return dynamic_cast<MeasuredDataFileDataItem*>(mdItem->childItems().at(0));
	}
	return nullptr;
}

void Post2dWindowDataModel::createCameraConnections()
{

}

void Post2dWindowDataModel::titleSetting()
{
	Post2dWindowRootDataItem* r = dynamic_cast<Post2dWindowRootDataItem*>(m_rootDataItem);
	r->titleDataItem()->showPropertyDialog();
}

void Post2dWindowDataModel::timeSetting()
{
	Post2dWindowRootDataItem* r = dynamic_cast<Post2dWindowRootDataItem*>(m_rootDataItem);
	r->timeDataItem()->showPropertyDialog();
}

void Post2dWindowDataModel::measuredDataPointSetting()
{
	MeasuredDataFileDataItem* fItem = getMeasuredDataFileDataItem();
	if (fItem == nullptr) {return;}
	fItem->pointGroupDataItem()->showPropertyDialog();
}

void Post2dWindowDataModel::measuredDataVectorSetting()
{
	MeasuredDataFileDataItem* fItem = getMeasuredDataFileDataItem();
	if (fItem == nullptr) {return;}
	fItem->vectorGroupDataItem()->showPropertyDialog();
}
