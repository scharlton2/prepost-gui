#include "projectcgnsmanager.h"
#include "projectmainfile.h"
#include "private/projectcgnsmanager_impl.h"

#include <misc/filesystemfunction.h>
#include <misc/stringtool.h>

#include <iriclib.h>

#include <QDir>

#include <sstream>

namespace {

const QString MAIN_FILENAME      = "Case1.cgn";
const QString MAIN_TMP_FILENAME  = "Case1.cgn.temp";

} // namespace

ProjectCgnsManager::ProjectCgnsManager(ProjectMainFile* mainFile) :
	impl {new Impl {mainFile}}
{}

ProjectCgnsManager::~ProjectCgnsManager()
{
	delete impl;
}

std::string ProjectCgnsManager::mainFileName() const
{
	return iRIC::toStr(MAIN_FILENAME);
}

std::string ProjectCgnsManager::mainFileFullName() const
{
	QDir dir(impl->m_mainFile->workDirectory());
	return iRIC::toStr(dir.absoluteFilePath(MAIN_FILENAME));
}

std::string ProjectCgnsManager::mainTmpFileFullName() const
{
	QDir dir(impl->m_mainFile->workDirectory());
	return iRIC::toStr(dir.absoluteFilePath(MAIN_TMP_FILENAME));
}

bool ProjectCgnsManager::deleteResultFolder()
{
	QDir dir(impl->m_mainFile->workDirectory());
	QString resultFolder = dir.absoluteFilePath("result");
	QDir resultDir(resultFolder);
	if (! resultDir.exists()) {return true;}

	return iRIC::rmdirRecursively(resultFolder);
}

QStringList ProjectCgnsManager::containedFiles() const
{
	QStringList ret;
	ret << MAIN_FILENAME;

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
