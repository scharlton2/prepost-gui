#ifndef GRAPH2DHYBRIDWINDOW_H
#define GRAPH2DHYBRIDWINDOW_H

#include <guicore/post/postprocessorwindow.h>
#include <guicore/base/additionalmenuwindow.h>

class ObjectBrowser;
class Graph2dHybridWindowObjectBrowser;
class Graph2dHybridWindowDataModel;
class Graph2dHybridWindowActionManager;
class Graph2dHybridWindowProjectDataItem;
class Graph2dHybridWindowControlWidget;

class Graph2dHybridWindow :
	public PostProcessorWindow,
	public AdditionalMenuWindow
{
	Q_OBJECT
public:
	explicit Graph2dHybridWindow(QWidget* parent, int index, Graph2dHybridWindowProjectDataItem* pdi);
	~Graph2dHybridWindow();
	QPixmap snapshot();
	QList<QMenu*> getAdditionalMenus();
	ObjectBrowser* objectBrowser();
	Graph2dHybridWindowControlWidget* controlWidget() {return m_controlWidget;}
signals:
	void closeButtonClicked();
private:
	void init();
	void setupDefaultGeometry(int index);

	Graph2dHybridWindowObjectBrowser* m_objectBrowser;
	Graph2dHybridWindowControlWidget* m_controlWidget;
	Graph2dHybridWindowDataModel* m_dataModel;
	Graph2dHybridWindowActionManager* m_actionManager;
	QByteArray m_initialState;

public:
	friend class Graph2dHybridWindowProjectDataItem;
	friend class Graph2dHybridWindowActionManager;
};

#endif // GRAPH2DHYBRIDWINDOW_H
