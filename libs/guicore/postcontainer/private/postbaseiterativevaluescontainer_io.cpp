#include "postbaseiterativevaluescontainer_impl.h"
#include "postbaseiterativevaluescontainer_io.h"
#include "../postsolutioninfo.h"
#include "../../project/projectdata.h"

#include <QDir>

namespace {

const QString FILENAME = "output.dat";

} // namespace

PostBaseIterativeValuesContainer::IO::IO(PostBaseIterativeValuesContainer* container) :
	m_container {container}
{
	QDir dir(container->impl->m_projectData->workDirectory());
	m_file.setFileName(dir.absoluteFilePath(FILENAME));
}

PostBaseIterativeValuesContainer::IO::~IO()
{}

QString PostBaseIterativeValuesContainer::IO::filename() const
{
	return FILENAME;
}
