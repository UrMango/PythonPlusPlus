#include "Type.h"

Type::Type(int type) : _type(type)
{
}

void Type::setIsTemp(const bool isTemp)
{
	this->_isTemp = isTemp;
}

bool Type::getIsTemp() const
{
	return this->_isTemp;
}
