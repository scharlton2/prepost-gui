#ifndef POSTBASEITERATIVEVALUECONTAINER_VALUECONTAINERT_H
#define POSTBASEITERATIVEVALUECONTAINER_VALUECONTAINERT_H

#include "../postbaseiterativevaluescontainer.h"
#include "postbaseiterativevaluescontainer_valuecontainer.h"

#include <string>
#include <vector>

template<class V>
class PostBaseIterativeValuesContainer::ValueContainerT : public PostBaseIterativeValuesContainer::ValueContainer
{
public:
	ValueContainerT();
	ValueContainerT(const std::string& name, int arrayId);

	const std::vector<V>& values() const;
	std::vector<V>& values();
	std::vector<double> doubleValues() const override;

	void addValue();
	void clear();

protected:
	std::vector<V> m_values;
};

#include "postbaseiterativevaluescontainer_valuecontainert_detail.h"

#endif // POSTBASEITERATIVEVALUECONTAINER_VALUECONTAINERT_H
