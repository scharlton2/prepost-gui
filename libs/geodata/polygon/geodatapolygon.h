#ifndef GEODATAPOLYGON_H
#define GEODATAPOLYGON_H

#include "gd_polygon_global.h"
#include <guicore/pre/geodata/geodata.h>
#include "geodatapolygoncolorsettingdialog.h"

#include <guicore/pre/grid/unstructured2dgrid.h>
#include <misc/zdepthrange.h>
#include <vtkSmartPointer.h>
#include <vtkPolygon.h>
#include <vtkUnstructuredGrid.h>
#include <vtkActor.h>
#include <vtkDataSetMapper.h>
#include <QVector>
#include <QPoint>
#include <QPointF>
#include <QPolygonF>
#include <QPixmap>
#include <QCursor>
#include <QVariant>
#include <QList>

#include <iriclib.h>

class QMenu;
class QAction;
class QToolBar;

class GridCreatingConditionCreatorTriangle;
class GeoDataPolygonTriangleThread;
class GeoDataPolygonAbstractPolygon;
class GeoDataPolygonRegionPolygon;
class GeoDataPolygonHolePolygon;
class GeoDataPolygonPolygonFinishDefiningCommand;
class GeoDataPolygonPolygonDefineNewPointCommand;
class GeoDataPolygonPolygonMoveCommand;
class GeoDataPolygonPolygonMoveVertexCommand;
class GeoDataPolygonPolygonRemoveVertexCommand;
class GeoDataPolygonPolygonAddVertexCommand;
class GeoDataPolygonPolygonCoordinatesEditCommand;
class GeoDataPolygonImporter;
class GeoDataPolygonShapeExporter;
class GeoDataPolygonProxy;
class PreProcessorBCSettingDataItem;

class GeoDataPolygonAddHolePolygonCommand;
class GeoDataPolygonEditValueCommand;

class GeoDataPolygonTriangleThread;

class GD_POLYGON_EXPORT GeoDataPolygon : public GeoData
{
	Q_OBJECT

private:
	const static int normalEdgeWidth = 1;
	const static int selectedEdgeWidth = 2;

public:
	enum SelectMode {
		smNone,
		smPolygon
	};
	enum MouseEventMode {
		meNormal,
		meBeforeDefining,
		meDefining,
		meTranslate,
		meTranslatePrepare,
		meMoveVertex,
		meMoveVertexPrepare,
		meAddVertex,
		meAddVertexPrepare,
		meAddVertexNotPossible,
		meRemoveVertexPrepare,
		meRemoveVertexNotPossible,

		meTranslateDialog,
		meEditVerticesDialog
	};
	/// Constructor
	GeoDataPolygon(ProjectDataItem* d, GeoDataCreator* creator, SolverDefinitionGridAttribute* condition);
	virtual ~GeoDataPolygon();
	void setupMenu() override;
	bool addToolBarButtons(QToolBar* /*parent*/) override;
	void informSelection(PreProcessorGraphicsViewInterface* v) override;
	void informDeselection(PreProcessorGraphicsViewInterface* v) override;
	void addCustomMenuItems(QMenu* menu) override;
	void viewOperationEnded(PreProcessorGraphicsViewInterface* /*v*/) override;
	void keyPressEvent(QKeyEvent* /*event*/, PreProcessorGraphicsViewInterface* /*v*/) override;
	void keyReleaseEvent(QKeyEvent* /*event*/, PreProcessorGraphicsViewInterface* /*v*/) override;
	void mouseDoubleClickEvent(QMouseEvent* /*event*/, PreProcessorGraphicsViewInterface* /*v*/) override;
	void mouseMoveEvent(QMouseEvent* /*event*/, PreProcessorGraphicsViewInterface* /*v*/) override;
	void mousePressEvent(QMouseEvent* /*event*/, PreProcessorGraphicsViewInterface* /*v*/) override;
	void mouseReleaseEvent(QMouseEvent* /*event*/, PreProcessorGraphicsViewInterface* /*v*/) override;
	void updateZDepthRangeItemCount(ZDepthRange& range) override;
	void assignActorZValues(const ZDepthRange& range) override;
	void definePolygon(bool doubleClick, bool noEditVal = false);
	QColor color() {return m_color;}
	QDialog* propertyDialog(QWidget* parent) override;
	void handlePropertyDialogAccepted(QDialog* d) override;
	void setMapping(GeoDataPolygonColorSettingDialog::Mapping m);
	GeoDataPolygonColorSettingDialog::Mapping mapping() {return m_mapping;}
	QColor doubleToColor(double d);
	void clear();
	bool ready() const {return true;}
	void showInitialDialog() override;
	const QVariant& variantValue() const;
	void setVariantValue(const QVariant& v);
	void setPolygon(const QPolygonF& p);
	void addHolePolygon(const QPolygonF& p);
	const QPolygonF polygon() const;
	vtkUnstructuredGrid* grid() const {return m_grid;}
	bool getValueRange(double* min, double* max) override;
	void updateFilename() override {
		m_filename = m_name;
		m_filename.append(".dat");
	}
	GeoDataProxy* getProxy() override;
	void copyShape(GeoDataPolygon* polygon);
	MouseEventMode mouseEventMode() const {return m_mouseEventMode;}
	SelectMode selectMode() const {return m_selectMode;}
	void setBCSettingMode(bool mode) {
		m_bcSettingMode = mode;
	}

public slots:
	void editValue();
	void restoreMouseEventMode();
	void handleDimensionCurrentIndexChange(int oldIndex, int newIndex) override;
	void handleDimensionValuesChange(const QList<QVariant>& before, const QList<QVariant>& after) override;

private slots:
	void updateGrid(bool noDraw = false);
	void addVertexMode(bool on);
	void removeVertexMode(bool on);
	void editCoordinates();
	void addHolePolygon();
	void deletePolygon(bool force = false);
	void editColorSetting();
	void renderGraphics();
	void copy();

protected:
	void updateMouseCursor(PreProcessorGraphicsViewInterface* v);
	void doLoadFromProjectMainFile(const QDomNode& node) override;
	void doSaveToProjectMainFile(QXmlStreamWriter& writer) override;
	void loadExternalData(const QString& filename) override;
	void saveExternalData(const QString& filename) override;
	void setColor(const QColor& color);
	void setColor(double r, double g, double b);
	int iRICLibType() const override {return IRIC_GEO_POLYGON;}
	void doApplyOffset(double x, double y) override;

private:
	bool checkCondition();
	void updateScalarValues();
	bool selectObject(QPoint point);
	void deselectAll();
	bool activePolygonHasFourVertices();
	void initParams();
	void updateMouseEventMode();
	void updateActionStatus();
	void setupHolePolygon(GeoDataPolygonHolePolygon* p);
	void applyOffsetToAbstractPolygon(GeoDataPolygonAbstractPolygon* polygon, double x, double y);
	void clearHolePolygons();
	ZDepthRange m_depthRange;

	QPoint m_dragStartPoint;
	QPoint m_currentPoint;

	SelectMode m_selectMode;
	MouseEventMode m_mouseEventMode;

	GeoDataPolygonRegionPolygon* m_gridRegionPolygon;
	QList<GeoDataPolygonHolePolygon*> m_holePolygons;

	GeoDataPolygonAbstractPolygon* m_selectedPolygon;

	QAction* m_holeModeAction;
	QAction* m_deleteAction;

	QAction* m_editValueAction;
	QAction* m_copyAction;
	QAction* m_addVertexAction;
	QAction* m_removeVertexAction;
	QAction* m_coordEditAction;
	QAction* m_editColorSettingAction;
	QMenu* m_rightClickingMenu;
	QColor m_color;
	int m_opacityPercent;
	GeoDataPolygonColorSettingDialog::Mapping m_mapping;
	QList<QVariant> m_variantValues;

	vtkSmartPointer<vtkUnstructuredGrid> m_grid;
	vtkSmartPointer<vtkActor> m_paintActor;
	vtkSmartPointer<vtkDataSetMapper> m_paintMapper;
	vtkSmartPointer<vtkDoubleArray> m_scalarValues;

	bool m_inhibitSelect;
	bool m_shapeUpdating;
	QPixmap m_addPixmap;
	QPixmap m_removePixmap;
	QPixmap m_movePointPixmap;
	QCursor m_addCursor;
	QCursor m_removeCursor;
	QCursor m_movePointCursor;

	GeoDataPolygonTriangleThread* m_triangleThread;

	double lastX;
	double lastY;

	bool m_bcSettingMode;

public:
	friend class GeoDataPolygonCreator;
	friend class GeoDataPolygonPropertyEditCommand;

	friend class GeoDataPolygonPolygonFinishDefiningCommand;
	friend class GeoDataPolygonPolygonDefineNewPointCommand;
	friend class GeoDataPolygonPolygonMoveCommand;
	friend class GeoDataPolygonPolygonMoveVertexCommand;
	friend class GeoDataPolygonPolygonRemoveVertexCommand;
	friend class GeoDataPolygonPolygonAddVertexCommand;
	friend class GeoDataPolygonCoordinatesEditCommand;
	friend class GeoDataPolygonAddHolePolygonCommand;
	friend class GeoDataPolygonEditValueCommand;

	friend class GeoDataPolygonCoordinatesEditDialog;
	friend class GeoDataPolygonAbstractPolygon;

	friend class GeoDataPolygonTriangleThread;
	friend class GeoDataPolygonImporter;
	friend class GeoDataPolygonShapeExporter;

	friend class GeoDataPolygonProxy;
	friend class PreProcessorBCSettingDataItem;
};

#endif // GEODATAPOLYGON_H