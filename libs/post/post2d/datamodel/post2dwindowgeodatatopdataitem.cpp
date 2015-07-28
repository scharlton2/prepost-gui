#include "post2dwindowgeodatagroupdataitem.h"
#include "post2dwindowgeodatatopdataitem.h"

#include <guicore/pre/base/preprocessorgeodatatopdataiteminterface.h>
#include <guicore/solverdef/solverdefinitiongridattribute.h>
#include <guicore/solverdef/solverdefinitiongridtype.h>
#include <pre/datamodel/preprocessorgeodatatopdataitem.h>

Post2dWindowGeoDataTopDataItem::Post2dWindowGeoDataTopDataItem(PreProcessorGeoDataTopDataItemInterface* ditem, Post2dWindowDataItem* parent)
	: Post2dWindowDataItem(tr("Geographic Data"), QIcon(":/libs/guibase/images/iconFolder.png"), parent)
{
	m_isDeletable = false;
	m_standardItem->setCheckable(true);
	m_standardItem->setCheckState(Qt::Checked);
	m_standardItemCopy = m_standardItem->clone();

	m_preGeoDataTopDataItem = ditem;

	// add child nodes.
	QList<SolverDefinitionGridAttribute*> list = ditem->gridType()->gridRelatedConditions();
	for (auto it = list.begin(); it != list.end(); ++it) {
		SolverDefinitionGridAttribute* cond = *it;
		QString tmpname = cond->name();
		if (tmpname.toLower().left(9) != "elevation") {continue;}
		Post2dWindowGeoDataGroupDataItem* i = new Post2dWindowGeoDataGroupDataItem(cond, this);
		m_childItems.append(i);
		m_itemNameMap.insert(cond->name(), i);
	}

	updateChildren();
	connect(ditem, SIGNAL(dataChanged()), this, SLOT(updateChildren()));
}

void Post2dWindowGeoDataTopDataItem::updateChildren()
{
	for (int i = 0; i < m_childItems.count(); ++i) {
		Post2dWindowGeoDataGroupDataItem* gItem = dynamic_cast<Post2dWindowGeoDataGroupDataItem*>(m_childItems.at(i));
		gItem->updateChildren();
	}
	assignActorZValues(m_zDepthRange);
}

void Post2dWindowGeoDataTopDataItem::doLoadFromProjectMainFile(const QDomNode& node)
{
	QDomNodeList children = node.childNodes();
	for (int i = 0; i < children.count(); ++i) {
		QDomElement child = children.at(i).toElement();
		QString name = child.attribute("name");
		Post2dWindowGeoDataGroupDataItem* item = m_itemNameMap.value(name);
		if (item != nullptr) {
			item->loadFromProjectMainFile(child);
		}
	}
}

void Post2dWindowGeoDataTopDataItem::doSaveToProjectMainFile(QXmlStreamWriter& writer)
{
	for (auto it = m_childItems.begin(); it != m_childItems.end(); ++it) {
		writer.writeStartElement("GeoDataGroup");
		(*it)->saveToProjectMainFile(writer);
		writer.writeEndElement();
	}
}
