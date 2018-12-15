#ifndef PROJECTMAINFILE_RESULTREMOVER_H
#define PROJECTMAINFILE_RESULTREMOVER_H

#include "../projectmainfile.h"

class ProjectMainFile::ResultRemover
{
public:
	static void removeResults(int fn);

private:
	ResultRemover();
};

#endif // PROJECTMAINFILE_RESULTREMOVER_H
