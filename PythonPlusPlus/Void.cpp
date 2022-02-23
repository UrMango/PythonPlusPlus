#include "Void.h"

Void::Void(bool isTemp = false) : Type(Types::_Void)
{
    this->setIsTemp(isTemp);
}

Void::~Void()
{
}

void* Void::getValue() const
{
    return nullptr;
}

bool Void::isPrintable() const
{
    return false;
}

std::string Void::toString() const
{
    return "";
}
