#include "postbaseiterativevaluescontainer_integervaluecontainer.h"

PostBaseIterativeValuesContainer::IntegerValueContainer::IntegerValueContainer() :
	ValueContainerT<int> ()
{}

PostBaseIterativeValuesContainer::IntegerValueContainer::IntegerValueContainer(const std::string& name, int arrayId) :
	ValueContainerT<int> (name, arrayId)
{}
