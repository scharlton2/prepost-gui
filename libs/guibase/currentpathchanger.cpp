#include "currentpathchanger.h"

#include <QDir>

CurrentPathChanger::CurrentPathChanger(QString newPath)
{
	m_oldPath = QDir::currentPath();
	QDir::setCurrent(newPath);
}

CurrentPathChanger::~CurrentPathChanger()
{
	QDir::setCurrent(m_oldPath);
}
