#include "postbaseiterativevaluescontainer_realvaluecontainer.h"

PostBaseIterativeValuesContainer::RealValueContainer::RealValueContainer() :
	ValueContainerT<double> ()
{}

PostBaseIterativeValuesContainer::RealValueContainer::RealValueContainer(const std::string& name, int arrayId) :
	ValueContainerT<double> (name, arrayId)
{}
