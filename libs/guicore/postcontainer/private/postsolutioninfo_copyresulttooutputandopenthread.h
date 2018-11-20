#ifndef POSTSOLUTIONINFO_COPYRESULTTOOUTPUTANDOPENTHREAD_H
#define POSTSOLUTIONINFO_COPYRESULTTOOUTPUTANDOPENTHREAD_H

#include "../postsolutioninfo.h"

#include <QThread>

class PostSolutionInfo::CopyResultToOutputAndOpenThread : public QThread
{
public:
	enum Result {
		Success,
		CopyError,
		OpenError,
	};

	CopyResultToOutputAndOpenThread(PostSolutionInfo* info);

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

#endif // POSTSOLUTIONINFO_COPYRESULTTOOUTPUTANDOPENTHREAD_H
