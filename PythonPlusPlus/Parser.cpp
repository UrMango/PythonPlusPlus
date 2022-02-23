#include "Parser.h"
#include "IndentationException.h"
#include "Integer.h"
#include "Boolean.h"
#include "String.h"
#include <iostream>
#include <string>


Type* Parser::parseString(std::string str)
{
	if (str.length() > 0)
	{
		// checks if the string starts with space or tab
		if (Parser::startsWith(str, " ") || Parser::startsWith(str, "	"))
			throw new IndentationException();
		std::cout << str << std::endl;
	}

	return nullptr;
}

Type* Parser::getType(std::string& str)
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
			Type* type = new Integer(0);
			type->setIsTemp(true);
			return type;
		}
		else 
		{ 
			// It's not an int - continue to check
		}
	else 
	{
		Type* type = new Integer(0);
		type->setIsTemp(true);
		return type;
	}
	
	if (str == "True") 
	{
		Type* type = new Boolean(true);
		type->setIsTemp(true);
		return type;
	}
	else if (str == "False") 
	{
		Type* type = new Boolean(false);
		type->setIsTemp(true);
		return type;
	}

	if (str[0] == '"' && str[str.length() - 1] == '"' || str[0] == 39 && str[str.length() - 1] == 39) // 39 - '
	{
		str.erase(0, 1); // remove the first " | '
		str.erase(str.length() - 1); // remove the last " | '

		Type* type = new String(str);
		type->setIsTemp(true);
		return type;
	}

	return nullptr;
}

bool Parser::startsWith(const std::string& text, const std::string& param)
{
	// returns 0 if the param is in the start of the string
	return text.compare(0, param.length(), param) == 0; 
}


