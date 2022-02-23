#include "Integer.h"

Integer::Integer(int value, bool isTemp = false) : _value(value)
{
	this->setIsTemp(isTemp);
}

Integer::~Integer()
{
}

bool Integer::isPrintable() const
{
	return true;
}

std::string Integer::toString() const
{
	return std::to_string(this->_value);
}
