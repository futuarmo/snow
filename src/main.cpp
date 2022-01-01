#include <iostream>
#include <string>

#include "analysis/lexer.h"


int main() {
	std::string line;

	do 
	{
		std::getline(std::cin, line);
		std::cout << "Line is: " << line << std::endl;
		Lexer p {line};

		Token tok = p.nextToken();
		while (tok.kind() != TokenKind::TokenEof)
		{
			std::cout << " == " << std::endl;
			std::cout << "Kind: " << static_cast<int>(tok.kind()) << std::endl;
			std::cout << "Value: " << tok.value() << std::endl;
			std::cout << "Position: " << tok.position() << std::endl;
			std::cout << " == " << std::endl;

			tok = p.nextToken();
		}

	} while (line != "");



	return 0;
}