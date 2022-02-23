#include "Type.h"

void Type::setIsTemp(const bool isTemp)
{
	this->_isTemp = isTemp;
}

bool Type::getIsTemp() const
{
	return this->_isTemp;
}
