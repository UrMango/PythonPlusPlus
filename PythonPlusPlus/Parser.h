#pragma once
#include "InterpreterException.h"
#include "Type.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>


class Parser
{
public:
	static Type* parseString(std::string str);
	static Type* getType(std::string& str);
private:
	static bool startsWith(const std::string& text, const std::string& param);

};
