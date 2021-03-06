#ifndef GRIDATTRIBUTEVARIATIONEDITWIDGET_H
#define GRIDATTRIBUTEVARIATIONEDITWIDGET_H

#include "../../../guicore_global.h"

#include <QWidget>
#include <vtkIdList.h>

class SolverDefinitionGridAttribute;
class GridAttributeContainer;
class vtkDataSetAttributes;
class PreProcessorGridDataItemInterface;

class GUICOREDLL_EXPORT GridAttributeVariationEditWidget : public QWidget
{
	Q_OBJECT

public:
	enum Mode {
		Difference,
		Ratio
	};

	GridAttributeVariationEditWidget(QWidget* parent, SolverDefinitionGridAttribute* condition);
	virtual ~GridAttributeVariationEditWidget();

	SolverDefinitionGridAttribute* gridAttribute() const;
	virtual void setMode(Mode mode);
	virtual void applyVariation(GridAttributeContainer* container, QVector<vtkIdType>& indices, vtkDataSetAttributes* atts, PreProcessorGridDataItemInterface* dItem) = 0;

protected:
	virtual void getValueFromInnerWidget() = 0;

	SolverDefinitionGridAttribute* m_gridAttribute;
	Mode m_mode;
};

#endif // GRIDATTRIBUTEVARIATIONEDITWIDGET_H
