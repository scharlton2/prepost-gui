#ifndef POSTABSTRACTSTEPS_H
#define POSTABSTRACTSTEPS_H

#include "../guicore_global.h"
#include "../project/projectdataitem.h"

class PostSolutionInfo;

/// This class is an abstract class that contains how many steps of
/// results are included in the current CGNS file.
class GUICOREDLL_EXPORT PostAbstractSteps : public ProjectDataItem
{

public:
	PostAbstractSteps(PostSolutionInfo* parent);

	virtual void loadFromCgnsFile(const int fn) override = 0;
	virtual bool dataExists() const = 0;

protected:
	PostSolutionInfo* postSolutionInfo() const;

private:
	void doLoadFromProjectMainFile(const QDomNode& node) override;
	void doSaveToProjectMainFile(QXmlStreamWriter& writer) override;
	virtual void clearArray() = 0;
};

#endif // POSTABSTRACTSTEPS_H
