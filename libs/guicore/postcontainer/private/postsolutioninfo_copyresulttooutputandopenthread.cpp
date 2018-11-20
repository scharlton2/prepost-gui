#include "postsolutioninfo_copyresulttooutputandopenthread.h"

#include <guicore/project/projectcgnsmanager.h>
#include <guicore/project/projectmainfile.h>

PostSolutionInfo::CopyResultToOutputAndOpenThread::CopyResultToOutputAndOpenThread(PostSolutionInfo* info) :
	QThread(),
	m_result {Success},
	m_progress {0},
	m_invalidDataId {0},
	m_solutionInfo {info}
{}

PostSolutionInfo::CopyResultToOutputAndOpenThread::Result PostSolutionInfo::CopyResultToOutputAndOpenThread::result() const
{
	return m_result;
}

int PostSolutionInfo::CopyResultToOutputAndOpenThread::progress() const
{
	return m_progress;
}

int PostSolutionInfo::CopyResultToOutputAndOpenThread::invalidDataId() const
{
	return m_invalidDataId;
}

void PostSolutionInfo::CopyResultToOutputAndOpenThread::run()
{
	bool ok = m_solutionInfo->mainFile()->cgnsManager()->copyResultToOutput(&m_progress, &m_invalidDataId);
	if (! ok) {
		m_result = CopyError;
		return;
	}

	ok = m_solutionInfo->open();
	if (! ok) {
		m_result = OpenError;
		return;
	}
	m_result = Success;
}
