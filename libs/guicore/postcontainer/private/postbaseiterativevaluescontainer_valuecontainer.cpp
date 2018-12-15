#include "postbaseiterativevaluescontainer_valuecontainer.h"

PostBaseIterativeValuesContainer::ValueContainer::ValueContainer() :
	ValueContainer(std::string(), 0)
{}

PostBaseIterativeValuesContainer::ValueContainer::ValueContainer(const std::string& name, int arrayId) :
	m_name (name),
	m_arrayId {arrayId}
{}

const std::string& PostBaseIterativeValuesContainer::ValueContainer::name() const
{
	return m_name;
}

void PostBaseIterativeValuesContainer::ValueContainer::setName(const std::string& name)
{
	m_name = name;
}

int PostBaseIterativeValuesContainer::ValueContainer::arrayId() const
{
	return m_arrayId;
}

void PostBaseIterativeValuesContainer::ValueContainer::setArrayId(int arrayId)
{
	m_arrayId = arrayId;
}
