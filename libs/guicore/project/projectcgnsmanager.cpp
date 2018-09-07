#include "projectcgnsmanager.h"
#include "private/projectcgnsmanager_impl.h"
#include "projectmainfile.h"
#include "../misc/cgnsfileopener.h"

#include <guibase/currentpathchanger.h>
#include <misc/filesystemfunction.h>
#include <misc/stringtool.h>

#include <iriclib.h>

#include <QDir>

#include <sstream>

namespace {

const QString INPUT_FILENAME      = "input.cgn";
const QString INPUT_TMP_FILENAME  = "input.cgn.temp";
const QString OUTPUT_FILENAME     = "output.cgn";
const QString TMP_FILENAME        = "output_tmp.cgn";
const QString OLD_OUTPUT_FILENAME = "Case1.cgn";

} // namespace

ProjectCgnsManager::ProjectCgnsManager(ProjectMainFile* mainFile) :
	impl {new Impl {mainFile, 0}}
{}

ProjectCgnsManager::~ProjectCgnsManager()
{
	delete impl;
}

std::string ProjectCgnsManager::inputFileName() const
{
	return iRIC::toStr(INPUT_FILENAME);
}

std::string ProjectCgnsManager::inputFileFullName() const
{
	QDir dir(impl->m_mainFile->workDirectory());
	return iRIC::toStr(dir.absoluteFilePath(INPUT_FILENAME));
}

std::string ProjectCgnsManager::inputTmpFileFullName() const
{
	QDir dir(impl->m_mainFile->workDirectory());
	return iRIC::toStr(dir.absoluteFilePath(INPUT_TMP_FILENAME));
}

std::string ProjectCgnsManager::outputFileName() const
{
	return iRIC::toStr(OUTPUT_FILENAME);
}

std::string ProjectCgnsManager::outputFileFullName() const
{
	QDir dir(impl->m_mainFile->workDirectory());
	return iRIC::toStr(dir.absoluteFilePath(OUTPUT_FILENAME));
}

void ProjectCgnsManager::incrementCopyIndex()
{
	++ impl->m_copyIndex;
}

int ProjectCgnsManager::copyIndex() const
{
	return impl->m_copyIndex;
}

std::string ProjectCgnsManager::copyFileFullName() const
{
	QString fullName("%1/result/output.copy%2.cgn");
	return iRIC::toStr(fullName.arg(impl->m_mainFile->workDirectory()).arg(impl->m_copyIndex));
}

std::string ProjectCgnsManager::oldOutputFileName() const
{
	return iRIC::toStr(OLD_OUTPUT_FILENAME);
}

std::string ProjectCgnsManager::oldOutputFileFullName() const
{
	QDir dir(impl->m_mainFile->workDirectory());
	return iRIC::toStr(dir.absoluteFilePath(OLD_OUTPUT_FILENAME));
}

std::string ProjectCgnsManager::importFileName() const
{
	if (inputFileExists()) {
		return inputFileName();
	} else if (outputFileExists()) {
		return outputFileName();
	} else {
		return oldOutputFileName();
	}
}

std::string ProjectCgnsManager::importFileFullName() const
{
	if (inputFileExists()) {
		return inputFileFullName();
	} else if (outputFileExists()) {
		return outputFileFullName();
	} else {
		return oldOutputFileFullName();
	}
}

std::string ProjectCgnsManager::resultFileName() const
{
	if (outputFileExists()) {
		return outputFileName();
	} else {
		return oldOutputFileName();
	}
}

std::string ProjectCgnsManager::resultFileFullName() const
{
	if (copyFileExists()) {
		return copyFileFullName();
	} else if (outputFileExists()) {
		return outputFileFullName();
	} else if (oldOutputFileExists()) {
		return oldOutputFileFullName();
	} else {
		return inputFileFullName();
	}
}

std::string ProjectCgnsManager::resultFileForStep(int step) const
{
	std::ostringstream ss;
	ss << "result/Solution" << (step + 1) << ".cgn";
	QDir dir(impl->m_mainFile->workDirectory());
	return iRIC::toStr(dir.absoluteFilePath(ss.str().c_str()));
}

bool ProjectCgnsManager::renameOldOutputToInput()
{
	if (inputFileExists()) {return true;}
	if (! oldOutputFileExists()) {return false;}

	QFile f(oldOutputFileFullName().c_str());
	return f.rename(inputFileFullName().c_str());
}

bool ProjectCgnsManager::copyInputToOutput()
{
	bool ok = deleteOutputFile();
	if (! ok) {return false;}

	QFile f(inputFileFullName().c_str());
	return f.copy(outputFileFullName().c_str());
}

bool ProjectCgnsManager::copyResultToOutput(int* progress, int* invalidDataId)
{
	CurrentPathChanger pathChanger(impl->m_mainFile->workDirectory());

	try {
		CgnsFileOpener opener(resultFileFullName(), CG_MODE_MODIFY);
		int ier = cg_iRIC_Init(opener.fileId());
		if (ier != 0) {return false;}
		ier = cg_iRIC_Combine_Solutions(opener.fileId(), progress, invalidDataId, -1);
		return true;
	} catch (...) {
		return false;
	}
}

bool ProjectCgnsManager::buildTmpFile(int* progress, int* invalidDataId)
{
	return true;
	/*
	CurrentPathChanger pathChanger(impl->m_mainFile->workDirectory());

	bool ok = copyInputToTmp();
	if (! ok) {return false;}

	try {
		CgnsFileOpener opener(tmpFileFullName(), CG_MODE_MODIFY);
		int ier = cg_iRIC_Init(opener.fileId());
		if (ier != 0) {return false;}
		ier = cg_iRIC_Combine_Solutions(opener.fileId(), progress, invalidDataId, -1);
		return true;
	} catch (...) {
		return false;
	}
	*/
}

bool ProjectCgnsManager::deleteInputFile()
{
	if (! inputFileExists()) {return true;}

	QFile f(inputFileFullName().c_str());
	return f.remove();
}

bool ProjectCgnsManager::deleteInputTmpFile()
{
	if (! inputTmpFileExists()) {return true;}

	QFile f(inputTmpFileFullName().c_str());
	return f.remove();
}

bool ProjectCgnsManager::deleteOutputFile()
{
	if (! outputFileExists()) {return true;}

	QFile f(outputFileFullName().c_str());
	return f.remove();
}

bool ProjectCgnsManager::deleteCopyFile()
{
	if (! copyFileExists()) {return true;}

	QFile f(copyFileFullName().c_str());
	return f.remove();
}

bool ProjectCgnsManager::deleteOldOutputFile()
{
	if (! oldOutputFileExists()) {return true;}

	QFile f(oldOutputFileFullName().c_str());
	return f.remove();
}

bool ProjectCgnsManager::deleteResultFolder()
{
	QDir dir(impl->m_mainFile->workDirectory());
	QString resultFolder = dir.absoluteFilePath("result");
	QDir resultDir(resultFolder);
	if (! resultDir.exists()) {return true;}

	return iRIC::rmdirRecursively(resultFolder);
}

bool ProjectCgnsManager::inputFileExists() const
{
	QFile f(inputFileFullName().c_str());
	return f.exists();
}

bool ProjectCgnsManager::inputTmpFileExists() const
{
	QFile f(inputTmpFileFullName().c_str());
	return f.exists();
}

bool ProjectCgnsManager::outputFileExists() const
{
	QFile f(outputFileFullName().c_str());
	return f.exists();
}

bool ProjectCgnsManager::copyFileExists() const
{
	QFile f(copyFileFullName().c_str());
	return f.exists();
}

bool ProjectCgnsManager::oldOutputFileExists() const
{
	QFile f(oldOutputFileFullName().c_str());
	return f.exists();
}

QStringList ProjectCgnsManager::containedFiles() const
{
	QStringList ret;
	if (inputFileExists()) {
		ret << INPUT_FILENAME;
	}
	ret << OUTPUT_FILENAME;

	QDir resultDir(impl->m_mainFile->workDirectory());
	bool ok = resultDir.cd("result");
	if (! ok) {return ret;}
	QStringList files = resultDir.entryList(QStringList(), QDir::Files);

	QDir rDir("result");
	for (const QString& file : files) {
		ret << rDir.filePath(file);
	}

	return ret;
}
