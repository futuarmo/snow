#pragma once
#include <string>
#include <vector>

#include "token.h"

class Lexer
{

public:
	Lexer(const std::string& line);
	Token nextToken();

private:
	char current();
	void next();

private:
	const std::string& m_line;
	int m_position{0};

};