#include "NameErrorException.h"

NameErrorException::NameErrorException(std::string name) : _name(name)
{
}

const char* NameErrorException::what() const noexcept
{
    std::string x = "NameError : name '" + this->_name + "' is not defined";
    const char* y = x.c_str();
    return y;
}
