#ifndef PROJECTCGNSMANAGER_IMPL_H
#define PROJECTCGNSMANAGER_IMPL_H

#include "../projectcgnsmanager.h"

class ProjectCgnsManager::Impl
{
public:
	ProjectMainFile* m_mainFile;
	int m_copyIndex;
};

#endif // PROJECTCGNSMANAGER_IMPL_H
