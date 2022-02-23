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

Type* Parser::getType(std::string str)
{
	int integer = 0;
	std::stringstream testInt(str);

	// remove spaces
	std::remove(str.begin(), str.end(), ' ');

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

	if(!varContent)
		throw new SyntaxException();

	varContent->setIsTemp(false);

	// Is variable exist already
	if(Parser::parseString(varName));

	Parser::_variables.insert({ varName, varContent });

	return true;
}

Type* Parser::getVariableValue(std::string str)
{
	std::unordered_map<std::string, Type*>::const_iterator found = Parser::_variables.find(str);
	if (found == Parser::_variables.end())
		return nullptr;
	else
		return found->second;
}

void Parser::deleteVariables()
{
	for (auto it = Parser::_variables.begin(); it != Parser::_variables.end(); it++) {
		delete it->second;
	}
}


