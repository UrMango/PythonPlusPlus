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
	static Type* getType(std::string str);
	static void deleteVariables();
private:
	static std::unordered_map<std::string, Type*> _variables;
	static bool startsWith(const std::string& text, const std::string& param);

	static bool isLegalVarName(std::string str);
	static bool makeAssignment(std::string str);
	static Type* getVariableValue(std::string str);
	static std::unordered_map<std::string, Type*>::const_iterator getVariable(std::string key);
};
