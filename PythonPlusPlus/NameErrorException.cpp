#include "NameErrorException.h"

NameErrorException::NameErrorException(std::string name) : _name(name)
{
}

const char* NameErrorException::what() const noexcept
{
    std::string y = "NameError : name '";
    y += this->_name;
    y += "' is not defined";
    char* x = new char[y.length() + 1];
    std::strcpy(x, y.c_str());
    return x;
}
