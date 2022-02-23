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
	// Could'nt make a static unorderd map
	static bool startsWith(const std::string& text, const std::string& param);

	static bool isLegalVarName(std::string str);
	static bool makeAssignment(std::string str);
	static Type* getVariableValue(std::string str);
	static void deleteVariables();
};
