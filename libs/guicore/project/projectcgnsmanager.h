#ifndef PROJECTCGNSMANAGER_H
#define PROJECTCGNSMANAGER_H

#include "../guicore_global.h"

#include <string>

class ProjectMainFile;

class QStringList;

class GUICOREDLL_EXPORT ProjectCgnsManager
{
public:
	ProjectCgnsManager(ProjectMainFile* mainFile);
	~ProjectCgnsManager();

	// The name of CGNS file that handles input data
	std::string inputFileName() const;
	std::string inputFileFullName() const;

	// The name of tmp file that cgnslib creates while saving input file.
	std::string inputTmpFileFullName() const;
	// The name of CGNS file that contains calculation result data
	std::string outputFileName() const;
	std::string outputFileFullName() const;

	// The name of CGNS file that contains calculation result data. It is a temp file that exists only when solver is running.
	void incrementCopyIndex();
	int copyIndex() const;
	std::string copyFileFullName() const;

	// Case1.cgn
	std::string oldOutputFileName() const;
	std::string oldOutputFileFullName() const;

	// The name of CGNS file that preprocessor should import input data from. When inputFileName() exists, it returns inputFileName(), and if not, outputFileName().
	std::string importFileName() const;
	std::string importFileFullName() const;
	// The name of CGNS file that post-processors should load result from. When the solver is running it is tmpFileName(), and when not running outputFileName().
	std::string resultFileName() const;
	std::string resultFileFullName() const;

	bool renameOldOutputToInput();
	bool copyInputToOutput();

	// Copy calculation result from result/Solution1.cgn etc. to result.cgn
	bool copyResultToOutput(int* progress, int* invalidDataId);
	bool buildTmpFile(int* progress, int* invalidDataId);

	bool deleteInputFile();
	bool deleteInputTmpFile();
	bool deleteOutputFile();
	bool deleteCopyFile();
	bool deleteOldOutputFile();
	bool deleteResultFolder();

	bool inputFileExists() const;
	bool inputTmpFileExists() const;
	bool outputFileExists() const;
	bool copyFileExists() const;
	bool oldOutputFileExists() const;

	QStringList containedFiles() const;

private:
	class Impl;
	Impl* impl;
};

#ifdef _DEBUG
	#include "private/projectcgnsmanager_impl.h"
#endif // _DEBUG

#endif // PROJECTCGNSMANAGER_H
