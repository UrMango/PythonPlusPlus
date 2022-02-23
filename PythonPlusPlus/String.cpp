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
	if (this->_value.find("'") != std::string::npos)
		return '"' + this->_value + '"';
	return "'" + this->_value + "'";
}
