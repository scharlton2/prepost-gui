#include "postbaseiterativevaluescontainer.h"
#include "postsolutioninfo.h"
#include "private/postbaseiterativevaluescontainer_basecontainer.h"
#include "private/postbaseiterativevaluescontainer_binaryio.h"
#include "private/postbaseiterativevaluescontainer_impl.h"
#include "private/postbaseiterativevaluescontainer_integervaluecontainer.h"
#include "private/postbaseiterativevaluescontainer_io.h"
#include "private/postbaseiterativevaluescontainer_realvaluecontainer.h"
#include "private/postbaseiterativevaluescontainer_textio.h"
#include "../misc/cgnsfileopener.h"
#include "../project/projectdata.h"
#include "../project/projectmainfile.h"

#include <QFile>

#include <cgnslib.h>

#include <stdexcept>

PostBaseIterativeValuesContainer::PostBaseIterativeValuesContainer(ProjectData* projectData) :
	impl {new Impl {}}
{
	impl->m_projectData = projectData;
	impl->m_io = new TextIO(this);
}

PostBaseIterativeValuesContainer::~PostBaseIterativeValuesContainer()
{
	impl->m_io->save();

	clear();
	delete impl;
}

QString PostBaseIterativeValuesContainer::filename() const
{
	return impl->m_io->filename();
}

void PostBaseIterativeValuesContainer::load()
{
	impl->m_io->load();
}

bool PostBaseIterativeValuesContainer::save()
{
	return impl->m_io->save();
}

void PostBaseIterativeValuesContainer::updateIfNeeded(int *progress, int *invalidId)
{
	*progress = 0;
	*invalidId = -1;

	int cCount = resultCgnsCount();
	int vCount = valueCount();

	if (vCount > cCount) {
		rebuild(progress, invalidId);
		return;
	}

	if (vCount < cCount) {
		if (vCount == 0) {
			setupContainers();
		}
		for (int solId = vCount; solId < cCount; ++solId) {
			bool ok = addValuesFor(solId);
			if (! ok) {
				*invalidId = solId;
				return;
			}
			*progress = static_cast<int>(100.0 * (solId + 1 - vCount) / (cCount - vCount));
		}
	}
}

const std::vector<PostBaseIterativeValuesContainer::BaseContainer*>& PostBaseIterativeValuesContainer::baseContainers() const
{
	return impl->m_baseContainers;
}

std::vector<PostBaseIterativeValuesContainer::BaseContainer*>& PostBaseIterativeValuesContainer::baseContainers()
{
	return impl->m_baseContainers;
}

PostBaseIterativeValuesContainer::BaseContainer* PostBaseIterativeValuesContainer::baseContainer(int baseId) const
{
	for (auto c : impl->m_baseContainers) {
		if (c->baseId() == baseId) {
			return c;
		}
	}
	return nullptr;
}

void PostBaseIterativeValuesContainer::rebuild(int* progress, int *invalidId)
{
	setupContainers();
	int cCount = resultCgnsCount();
	*progress = 0;
	*invalidId = -1;
	for (int solId = 0; solId < cCount; ++solId) {
		bool ok = addValuesFor(solId);
		if (! ok) {
			*invalidId = solId;
			return;
		}
		*progress = static_cast<int>(100.0 * (solId + 1) / cCount);
	}
}

void PostBaseIterativeValuesContainer::setupContainers()
{
	impl->m_baseContainers.clear();

	auto cgnsName = impl->m_projectData->mainfile()->postSolutionInfo()->resultCgnsFileNameForStep(0);
	QFile f(cgnsName.c_str());
	if (! f.exists()) {return;}

	try {
		CgnsFileOpener opener(cgnsName, CG_MODE_READ);
		int nbases, ier;
		ier = cg_nbases(opener.fileId(), &nbases);
		if (ier != 0) {return;}

		for (int baseId = 1; baseId <= nbases; ++baseId) {
			auto c = new BaseContainer(baseId);
			c->setupContainers(opener.fileId());
			impl->m_baseContainers.push_back(c);
		}
	} catch (...) {
		// do nothing
	}
}

bool PostBaseIterativeValuesContainer::addValuesFor(int solId)
{
	try {
		CgnsFileOpener opener(impl->m_projectData->mainfile()->postSolutionInfo()->resultCgnsFileNameForStep(solId), CG_MODE_READ);
		for (auto c : impl->m_baseContainers) {
			c->addValues(opener.fileId());
		}
		return true;
	} catch (...) {
		return false;
	}
}

void PostBaseIterativeValuesContainer::clear()
{
	for (auto c : impl->m_baseContainers) {
		delete c;
	}
	impl->m_baseContainers.clear();
}

int PostBaseIterativeValuesContainer::resultCgnsCount() const
{
	int solId = 0;
	PostSolutionInfo* postSolutionInfo = impl->m_projectData->mainfile()->postSolutionInfo();

	while (true) {
		auto fName = postSolutionInfo->resultCgnsFileNameForStep(solId);

		QFile f(fName.c_str());
		if (! f.exists()) {
			return solId;
		}
		++ solId;
	}
}

int PostBaseIterativeValuesContainer::valueCount() const
{
	for (const auto& c : impl->m_baseContainers) {
		if (c->integerContainers().size() > 0) {
			auto ic = c->integerContainers().at(0);
			return static_cast<int>(ic->values().size());
		}
		if (c->realContainers().size() > 0) {
			auto rc = c->realContainers().at(0);
			return static_cast<int>(rc->values().size());
		}
	}
	return 0;
}
