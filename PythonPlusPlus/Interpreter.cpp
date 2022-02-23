#include "Type.h"
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>
#include <sstream>

#define WELCOME "Welcome to the Python Interperter (Python++) version 1.0 by "
#define NAME "Noam Raz"


int main(int argc, char** argv)
{
	std::cout << WELCOME << NAME << "!" << std::endl;

	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);

	while (input_string != "quit()")
	{
		try {
			// parsing command
			Type* type = Parser::parseString(input_string);
			if (type->isPrintable())
				std::cout << type->toString() << std::endl;
			if (type->getIsTemp())
				delete type;
		}
		catch (InterpreterException* e) {
			std::cout << e->what() << std::endl;
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}
	Parser::deleteVariables();
	return 0;
}
