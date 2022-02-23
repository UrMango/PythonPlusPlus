#include "Integer.h"

Integer::Integer(int value, bool isTemp = false) : _value(value), Type(Types::_Int)
{
	this->setIsTemp(isTemp);
}

Integer::~Integer()
{
}

void* Integer::getValue() const
{
	return (void*)&_value;
}

bool Integer::isPrintable() const
{
	return true;
}

std::string Integer::toString() const
{
	return std::to_string(this->_value);
}
