#include "Void.h"

Void::Void(bool isTemp = false)
{
    this->setIsTemp(isTemp);
}

Void::~Void()
{
}

bool Void::isPrintable() const
{
    return false;
}

std::string Void::toString() const
{
    return "";
}
