#ifndef CURRENTPATHCHANGER_H
#define CURRENTPATHCHANGER_H

#include "guibase_global.h"

#include <QString>

class GUIBASEDLL_EXPORT CurrentPathChanger
{
public:
	CurrentPathChanger(QString newPath);
	~CurrentPathChanger();

private:
	QString m_oldPath;
};

#endif // CURRENTPATHCHANGER_H
