#include "postdatacontainer.h"
#include "postsolutioninfo.h"

#include "../project/projectdata.h"
#include "../project/projectmainfile.h"

PostDataContainer::PostDataContainer(ProjectDataItem* parent) :
	ProjectDataItem {parent}
{}

bool PostDataContainer::handleCurrentStepUpdate(const int)
{
	return true;
}

PostSolutionInfo* PostDataContainer::postSolutionInfo() const
{
	return projectData()->mainfile()->postSolutionInfo();
}
