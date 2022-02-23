#include "Parser.h"
#include "IndentationException.h"
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

bool Parser::startsWith(const std::string& text, const std::string& param)
{
	// returns 0 if the param is in the start of the string
	return text.compare(0, param.length(), param) == 0; 
}


