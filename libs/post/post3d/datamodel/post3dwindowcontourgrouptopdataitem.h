#ifndef POST3DWINDOWCONTOURGROUPTOPDATAITEM_H
#define POST3DWINDOWCONTOURGROUPTOPDATAITEM_H

#include "../post3dwindowdataitem.h"

class Post3dWindowContourGroupTopDataItem : public Post3dWindowDataItem
{
	Q_OBJECT

public:
	Post3dWindowContourGroupTopDataItem(Post3dWindowDataItem* p);
	~Post3dWindowContourGroupTopDataItem();

	void innerUpdateZScale(double scale) override;
	void update();

public slots:
	void addContour();

protected:
	void doLoadFromProjectMainFile(const QDomNode&) override;
	void doSaveToProjectMainFile(QXmlStreamWriter&) override;
	void addCustomMenuItems(QMenu* menu) override;

	QDialog* dialog(QWidget* p);
	void accept(QDialog* propDialog);

private:
	QMap<std::string, QString> m_colorBarTitleMap;
	double m_zScale;
	QAction* m_addAction;

	friend class Post3dWindowContourGroupDataItem;

	class CreateCommand;
};

#endif // POST3DWINDOWCONTOURGROUPTOPDATAITEM_H
