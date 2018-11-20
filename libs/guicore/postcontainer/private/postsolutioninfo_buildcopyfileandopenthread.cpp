#include "postsolutioninfo_buildcopyfileandopenthread.h"

#include <guicore/project/projectcgnsmanager.h>
#include <guicore/project/projectmainfile.h>

PostSolutionInfo::BuildCopyFileAndOpenThread::BuildCopyFileAndOpenThread(PostSolutionInfo* info) :
	QThread(),
	m_result {Success},
	m_progress {0},
	m_invalidDataId {0},
	m_solutionInfo {info}
{}

PostSolutionInfo::BuildCopyFileAndOpenThread::Result PostSolutionInfo::BuildCopyFileAndOpenThread::result() const
{
	return m_result;
}

int PostSolutionInfo::BuildCopyFileAndOpenThread::progress() const
{
	return m_progress;
}

int PostSolutionInfo::BuildCopyFileAndOpenThread::invalidDataId() const
{
	return m_invalidDataId;
}

void PostSolutionInfo::BuildCopyFileAndOpenThread::run()
{
	bool ok = m_solutionInfo->mainFile()->cgnsManager()->buildCopyFile(&m_progress, &m_invalidDataId);
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
