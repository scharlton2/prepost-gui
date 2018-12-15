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
const QString OLD_OUTPUT_FILENAME = "Case1.cgn";

} // namespace

ProjectCgnsManager::ProjectCgnsManager(ProjectMainFile* mainFile) :
	impl {new Impl {mainFile}}
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
	} else {
		return oldOutputFileName();
	}
}

std::string ProjectCgnsManager::importFileFullName() const
{
	if (inputFileExists()) {
		return inputFileFullName();
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
	if (outputFileExists()) {
		return outputFileFullName();
	} else {
		return oldOutputFileFullName();
	}
}

std::string ProjectCgnsManager::resultFileForStep(int step) const
{
	std::ostringstream ss;
	ss << "result/Solution" << (step + 1) << ".cgn";
	QDir dir(impl->m_mainFile->workDirectory());
	return iRIC::toStr(dir.absoluteFilePath(ss.str().c_str()));
}

bool ProjectCgnsManager::renameOldOutputToOutput()
{
	if (! oldOutputFileExists()) {return true;}

	QFile f(oldOutputFileFullName().c_str());
	return f.rename(outputFileFullName().c_str());
}

bool ProjectCgnsManager::copyOutputToInput()
{
	if (! outputFileExists()) {return true;}
	if (inputFileExists()) {return true;}

	QFile f(outputFileFullName().c_str());
	return f.copy(inputFileFullName().c_str());
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
