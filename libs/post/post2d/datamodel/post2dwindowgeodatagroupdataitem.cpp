#include "post2dwindowgeodatadataitem.h"
#include "post2dwindowgeodatagroupdataitem.h"
#include "post2dwindowgeodatatopdataitem.h"

#include <guicore/pre/base/preprocessorgeodatadataiteminterface.h>
#include <guicore/pre/base/preprocessorgeodatagroupdataiteminterface.h>
#include <guicore/pre/base/preprocessorgeodatatopdataiteminterface.h>
#include <guicore/pre/geodata/geodata.h>
#include <guicore/pre/geodata/geodataproxy.h>
#include <guicore/solverdef/solverdefinitiongridattribute.h>

#include <QMap>

Post2dWindowGeoDataGroupDataItem::Post2dWindowGeoDataGroupDataItem(SolverDefinitionGridAttribute* cond, Post2dWindowDataItem* parent)
	: Post2dWindowDataItem(cond->caption(), QIcon(":/libs/guibase/images/iconFolder.png"), parent)
{
	m_condition = cond;
	m_isDeletable = false;
	m_standardItem->setCheckable(true);
	m_standardItem->setCheckState(Qt::Checked);

	m_standardItemCopy = m_standardItem->clone();
}


void Post2dWindowGeoDataGroupDataItem::updateChildren()
{
	Post2dWindowGeoDataTopDataItem* tItem = dynamic_cast<Post2dWindowGeoDataTopDataItem*>(parent());
	PreProcessorGeoDataTopDataItemInterface* rtItem = tItem->preGeoDataTopDataItem();
	PreProcessorGeoDataGroupDataItemInterface* gItem = rtItem->groupDataItem(m_condition->name());

	QList <GraphicsWindowDataItem*> oldChildren = m_childItems;
	QMap<GeoData*, Post2dWindowGeoDataDataItem*> map;
	for (int i = 0; i < oldChildren.count(); ++i) {
		Post2dWindowGeoDataDataItem* item = dynamic_cast<Post2dWindowGeoDataDataItem*>(oldChildren.at(i));
		map.insert(item->geoDataProxy()->geoData(), item);
		m_standardItem->takeRow(0);
	}
	m_childItems.clear();
	m_itemNameMap.clear();

	QList <GraphicsWindowDataItem*> origChildren = gItem->childItems();
	for (int i = 0; i < origChildren.count(); ++i) {
		PreProcessorGeoDataDataItemInterface* item = dynamic_cast<PreProcessorGeoDataDataItemInterface*>(origChildren.at(i));
		GeoData* geoData = item->geoData();
		if (map.contains(geoData)) {
			m_childItems.append(map.value(geoData));
			m_standardItem->appendRow(map.value(geoData)->standardItem());
			oldChildren.removeOne(map.value(geoData));
			m_itemNameMap.insert(geoData->name(), map.value(geoData));
		} else {
			// try to add.
			GeoDataProxy* proxy = geoData->getProxy();
			connect(geoData, SIGNAL(graphicsUpdated()), proxy, SLOT(updateGraphics()));
			if (proxy != nullptr) {
				Post2dWindowGeoDataDataItem* pItem = new Post2dWindowGeoDataDataItem(this);
				pItem->setGeoDataProxy(proxy);
				proxy->setupDataItem();
				m_childItems.append(pItem);
				m_itemNameMap.insert(geoData->name(), pItem);
				connect(item, SIGNAL(captionChanged(QString)), pItem, SLOT(updateCaption(QString)));
			}
		}
	}
	for (int i = 0; i < oldChildren.count(); ++i) {
		delete oldChildren.at(i);
	}
	assignActorZValues(m_zDepthRange);
	updateItemMap();
}

void Post2dWindowGeoDataGroupDataItem::doLoadFromProjectMainFile(const QDomNode& node)
{
	QDomNodeList children = node.childNodes();
	for (int i = 0; i < children.count(); ++i) {
		QDomElement elem = children.at(i).toElement();
		QString name = elem.attribute("name");
		if (m_itemNameMap.contains(name)) {
			Post2dWindowGeoDataDataItem* item = m_itemNameMap.value(name);
			item->loadFromProjectMainFile(elem);
		}
	}
	updateChildren();
}

void Post2dWindowGeoDataGroupDataItem::doSaveToProjectMainFile(QXmlStreamWriter& writer)
{
	writer.writeAttribute("name", m_condition->name());
	for (auto it = m_childItems.begin(); it != m_childItems.end(); ++it) {
		writer.writeStartElement("GeoData");
		(*it)->saveToProjectMainFile(writer);
		writer.writeEndElement();
	}
}