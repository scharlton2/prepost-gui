#ifndef POSTSOLUTIONINFO_BUILDCOPYFILEANDOPENTHREAD_H
#define POSTSOLUTIONINFO_BUILDCOPYFILEANDOPENTHREAD_H

#include "../postsolutioninfo.h"

#include <QThread>

class PostSolutionInfo::BuildCopyFileAndOpenThread : public QThread
{
public:
	enum Result {
		Success,
		CopyError,
		OpenError,
	};

	BuildCopyFileAndOpenThread(PostSolutionInfo* info);

	Result result() const;
	int progress() const;
	int invalidDataId() const;

private:
	void run() override;

	Result m_result;
	int m_progress;
	int m_invalidDataId;

	PostSolutionInfo* m_solutionInfo;
};

#endif // POSTSOLUTIONINFO_BUILDCOPYFILEANDOPENTHREAD_H
