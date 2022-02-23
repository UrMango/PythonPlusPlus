#include "Boolean.h"

Boolean::Boolean(bool value, bool isTemp = false) : _value(value), Type(Types::_Bool)
{
	this->setIsTemp(isTemp);
}

Boolean::~Boolean()
{
}

void* Boolean::getValue() const
{
	return (void*)&_value;
}

bool Boolean::isPrintable() const
{
	return true;
}

std::string Boolean::toString() const
{
	if (this->_value)
		return "True";
	else
		return "False";
}
