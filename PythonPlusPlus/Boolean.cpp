#include "Boolean.h"

Boolean::Boolean(bool value, bool isTemp = false) : _value(value)
{
	this->setIsTemp(isTemp);
}

Boolean::~Boolean()
{
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
