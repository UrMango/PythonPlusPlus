#include "String.h"

String::String(std::string value) : _value(value)
{
}

String::~String()
{
}

bool String::isPrintable() const
{
	return true;
}

std::string String::toString() const
{
	return this->_value;
}
