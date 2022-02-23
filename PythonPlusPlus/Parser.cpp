#include "Parser.h"
#include "IndentationException.h"
#include "SyntaxException.h"
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

		str.erase(str.find_last_not_of(" ") + 1); // remove spaces from end

		Type* type = Parser::getType(str);
		if (type) // if not null
			return type;
		else
			throw new SyntaxException();
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


