#include "Type.h"
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>

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
			Parser::parseString(input_string);
		}
		catch (InterpreterException* e) {
			std::cout << e->what() << std::endl;
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}

	return 0;
}
