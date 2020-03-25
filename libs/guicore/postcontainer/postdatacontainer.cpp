#include "postdatacontainer.h"
#include "postsolutioninfo.h"

#include "../project/projectdata.h"
#include "../project/projectmainfile.h"

PostDataContainer::PostDataContainer(PostSolutionInfo *parent) :
	ProjectDataItem {parent}
{}

bool PostDataContainer::handleCurrentStepUpdate(const int /*fn*/, const int /*timeStep*/)
{
	return true;
}

PostSolutionInfo* PostDataContainer::postSolutionInfo() const
{
	return projectData()->mainfile()->postSolutionInfo();
}
