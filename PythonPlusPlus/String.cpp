#include "String.h"

String::String(std::string value, bool isTemp = false) : _value(value), Sequence(Types::_String)
{
	this->setIsTemp(isTemp);
}

String::~String()
{
}

void* String::getValue() const
{
	return (void*)&_value;
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
