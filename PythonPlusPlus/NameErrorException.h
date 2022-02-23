#pragma once
#include <iostream>
#include <string>
#include <format>
#include "InterpreterException.h"

class NameErrorException : public InterpreterException
{
private:
	std::string _name = "";
public:
	NameErrorException(std::string name);
	virtual const char* what() const noexcept;
};

