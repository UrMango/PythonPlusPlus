#include "Parser.h"
#include "IndentationException.h"
#include "SyntaxException.h"
#include "NameErrorException.h"
#include "Integer.h"
#include "Boolean.h"
#include "String.h"
#include "Void.h"
#include <iostream>
#include <string>

std::unordered_map<std::string, Type*> Parser::_variables;

Type* Parser::parseString(std::string str)
{
	if (str.length() > 0)
	{
		// checks if the string starts with space or tab
		if (Parser::startsWith(str, " ") || Parser::startsWith(str, "	"))
			throw new IndentationException();

 		//str.erase(str.find_last_not_of(" ") + 1); // remove spaces from end
		Helper::rtrim(str);

		Type* type = Parser::getVariableValue(str);
		if (type)
			return type;
		type = Parser::getType(str);
		if (type) // if not null
			return type;
		if (Parser::makeAssignment(str))
			return new Void(true);
		throw new NameErrorException(str);
	}

	return nullptr;
}

Type* Parser::getType(std::string& str1)
{
	std::string str = str1;

	int integer = 0;
	std::stringstream testInt(str);

	// remove spaces
	Helper::trim(str);

	// Check if the string is an integer
	testInt >> integer;

	if (integer == 0) // 0 is what returns if the value isn't an integer
		if (str == "0")  // but it can also be the real value, so i'm checking
		{
			return new Integer(0, true);;
		}
		else 
		{ 
			// It's not an int - continue to check
		}
	else 
	{
		return new Integer(integer, true);
	}
	
	if (str == "True") 
	{
		return new Boolean(true, true);
	}
	else if (str == "False") 
	{
		return new Boolean(false, true);
	}

	if (str[0] == '"' && str[str.length() - 1] == '"' || str[0] == 39 && str[str.length() - 1] == 39) // 39 - '
	{
		str.erase(0, 1); // remove the first " | '
		str.erase(str.length() - 1); // remove the last " | '

		return new String(str, true);
	}

	return nullptr;
}

bool Parser::startsWith(const std::string& text, const std::string& param)
{
	// returns 0 if the param is in the start of the string
	return text.compare(0, param.length(), param) == 0; 
}

bool Parser::isLegalVarName(std::string str)
{
	if (Helper::isDigit(str[0]))
		return false;
	for (int i = 0; i < str.length(); i++)
	{
		if(!Helper::isDigit(str[i]) && !Helper::isUnderscore(str[i]) && !Helper::isLetter(str[i]))
			return false;
	}
	return true;
}

bool Parser::makeAssignment(std::string str)
{
	if (str[0] == '=' || str[str.length() - 1] == '=')
		return false;
	int equalIndx = str.find("=");
	if (equalIndx != std::string::npos)
	{
		if (str[equalIndx - 1] != ' ' || str[equalIndx + 1] != ' ')
			return false;
	}
	else
		return false;

	std::string varName = str.substr(0, equalIndx);
	Helper::trim(varName);

	std::string varContentStr = str.substr(equalIndx + 1, str.length() - equalIndx);
	Helper::trim(varContentStr);

	if (!Parser::isLegalVarName(varName))
		throw new SyntaxException();


	Type* varContent = Parser::getType(varContentStr);
	std::unordered_map<std::string, Type*>::iterator contentVar;

	if (!varContent) 
	{
		if (Parser::isLegalVarName(varContentStr)) // if legal
			contentVar = Parser::getVariable(varContentStr);
		else
			throw new SyntaxException();

		if (contentVar != Parser::_variables.end()) //if content is a var
			varContent = Parser::copyVar(contentVar->second);
	}

	varContent->setIsTemp(false);	
	
	// Is variable exist already
	std::unordered_map<std::string, Type*>::iterator var = Parser::getVariable(varName);
	if (var != Parser::_variables.end()) // false = there's no variable
	{
		var->second = varContent; // change the content
		return true;
	}

	Parser::_variables.insert({ varName, varContent });

	return true;
}

Type* Parser::copyVar(Type* var)
{
	switch (var->_type)
	{
	case Types::_Void:
		return new Void(var->getIsTemp());
	case Types::_Bool:
		return new Boolean(*((bool*)var->getValue()), var->getIsTemp());
	case Types::_Int:
		return new Integer(*((int*)var->getValue()), var->getIsTemp());
	case Types::_String:
		return new String(*((std::string*)var->getValue()), var->getIsTemp());
	default:
		break;
	}
}

Type* Parser::getVariableValue(std::string str)
{
	std::unordered_map<std::string, Type*>::const_iterator found = Parser::_variables.find(str);
	if (found == Parser::_variables.end())
		return nullptr;
	else
		return found->second;
}

std::unordered_map<std::string, Type*>::iterator Parser::getVariable(std::string key)
{
	std::unordered_map<std::string, Type*>::iterator found = Parser::_variables.find(key);
	return found;
}

void Parser::deleteVariables()
{
	for (auto it = Parser::_variables.begin(); it != Parser::_variables.end(); it++) 
		delete it->second;
}


