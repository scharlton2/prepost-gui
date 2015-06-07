#ifndef PREPROCESSORGRIDRELATEDCONDITIONNODEGROUPDATAITEM_H
#define PREPROCESSORGRIDRELATEDCONDITIONNODEGROUPDATAITEM_H

#include <guicore/pre/base/preprocessordataitem.h>
#include <QMap>
#include <vtkActor.h>
#include <vtkDataSetMapper.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkSmartPointer.h>
#include <vtkContourFilter.h>

class QAction;
class PreProcessorGridAttributeNodeDataItem;

class PreProcessorGridAttributeNodeGroupDataItem : public PreProcessorDataItem
{
	Q_OBJECT
public:
	/// Constructor
	PreProcessorGridAttributeNodeGroupDataItem(PreProcessorDataItem* parent);
	~PreProcessorGridAttributeNodeGroupDataItem();
	void updateActorSettings();
	const QString& currentCondition() {return m_currentCondition;}
	void informDataChange(const QString& name);
	void setupActors();
	void updateZDepthRangeItemCount() override;
	void informSelection(VTKGraphicsView* v) override;
	void informDeselection(VTKGraphicsView* v) override;
	void mouseMoveEvent(QMouseEvent* event, VTKGraphicsView* v) override;
	void mouseReleaseEvent(QMouseEvent* event, VTKGraphicsView* v) override;
	void assignActorZValues(const ZDepthRange& range) override;
	void informGridUpdate();
	void setCurrentCondition(const QString& currentCond);
	const QList<PreProcessorGridAttributeNodeDataItem*> conditions() const;
	PreProcessorGridAttributeNodeDataItem* nodeDataItem(const QString& name) {return m_nameMap.value(name, 0);}
	void handleStandardItemChange() override;
	void setOpacityPercent(int o) {m_opacityPercent = o;}
	int opacityPercent() {return m_opacityPercent;}
	void informSelectedVerticesChanged(const QVector<vtkIdType>& vertices);
	QAction* showAttributeBrowserAction() const {return m_showAttributeBrowserAction;}
	void addCustomMenuItems(QMenu* menu) override;
	void initAttributeBrowser();
	void clearAttributeBrowser();
	void fixAttributeBrowser(const QPoint& p, VTKGraphicsView* v);
	void updateAttributeBrowser(const QPoint& p, VTKGraphicsView* v);
	bool addToolBarButtons(QToolBar* toolbar) override;

public slots:
	void exclusivelyCheck(PreProcessorGridAttributeNodeDataItem*);
	void showAttributeBrowser();

protected:
	PreProcessorGridAttributeNodeDataItem* activeChildItem();
	void doLoadFromProjectMainFile(const QDomNode& node) override;
	void doSaveToProjectMainFile(QXmlStreamWriter& writer) override;
	void updateAttributeBrowser(vtkIdType vid, double x, double y, VTKGraphicsView* v);

private:
	vtkIdType findVertex(const QPoint& p, VTKGraphicsView* v);

	QString m_currentCondition;
	vtkSmartPointer<vtkPolyData> m_contourPolyData;
	vtkSmartPointer<vtkActor> m_contourActor;
	vtkSmartPointer<vtkDataSetMapper> m_contourMapper;
	vtkSmartPointer<vtkActor> m_isolineActor;
	vtkSmartPointer<vtkPolyDataMapper> m_isolineMapper;
	vtkSmartPointer<vtkContourFilter> m_isolineFilter;
	vtkSmartPointer<vtkActor> m_fringeActor;
	vtkSmartPointer<vtkDataSetMapper> m_fringeMapper;

	QAction* m_showAttributeBrowserAction;
	int m_opacityPercent;
	bool m_attributeBrowserFixed;
	QMap<QString, PreProcessorGridAttributeNodeDataItem*> m_nameMap;
public:
	friend class PreProcessorSelectCondition;
};

#endif // PREPROCESSORGRIDRELATEDCONDITIONNODEGROUPDATAITEM_H