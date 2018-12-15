#ifndef POSTBASEITERATIVEVALUESCONTAINER_VALUECONTAINER_H
#define POSTBASEITERATIVEVALUESCONTAINER_VALUECONTAINER_H

#include "../postbaseiterativevaluescontainer.h"

class PostBaseIterativeValuesContainer::ValueContainer
{
public:
	ValueContainer();
	ValueContainer(const std::string& name, int arrayId);

	const std::string& name() const;
	void setName(const std::string& name);

	int arrayId() const;
	void setArrayId(int arrayId);

	virtual std::vector<double> doubleValues() const = 0;

protected:
	std::string m_name;
	int m_arrayId;
};

#endif // POSTBASEITERATIVEVALUESCONTAINER_VALUECONTAINER_H
