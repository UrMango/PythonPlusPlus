#include "Boolean.h"

Boolean::Boolean(bool value) : _value(value)
{
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
