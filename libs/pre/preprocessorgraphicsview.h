#ifndef PREPROCESSORGRAPHICSVIEW_H
#define PREPROCESSORGRAPHICSVIEW_H

#include <guicore/pre/base/preprocessorgraphicsviewinterface.h>

class PreProcessorGraphicsView : public PreProcessorGraphicsViewInterface
{

public:
	PreProcessorGraphicsView(QWidget* parent);
	~PreProcessorGraphicsView();
};

#endif // PREPROCESSORGRAPHICSVIEW_H
