#include "lexer.h"

Lexer::Lexer(const std::string& line) : m_line(line), m_position(0)
{
}

char Lexer::current()
{
	if (m_position >= m_line.size())
	{
		return '\0';
	}

	return m_line[m_position];
}

void Lexer::next()
{
	m_position++;
}

Token Lexer::nextToken()
{
	if (std::isspace(current()))
	{
		while (std::isspace(current()))
		{
			next();
		}
	}

	int start = m_position;

	if (std::isdigit(current()))
	{
		while (std::isdigit(current()))
		{
			next();
		}

		return Token{TokenKind::TokenNumber,
			start, std::string_view{m_line.begin() + start, m_line.begin() + m_position}};
	}
	else if (std::isalpha(current()) || current() == '_')
	{
		while (std::isalpha(current()) || std::isdigit(current()) || current() == '_')
		{
			next();
		}

		return Token{TokenKind::TokenIdentifier,
			start, std::string_view{m_line.begin() + start, m_line.begin() + m_position}};
	}

	if (current() == '+')
	{
		return Token{TokenKind::TokenPlus, m_position++, "+"};
	}
	else if (current() == '-')
	{
		return Token{TokenKind::TokenMinus, m_position++, "-"};
	} 
	else if (current() == '*')
	{
		return Token{TokenKind::TokenStar, m_position++, "*"};
	}
	else if (current() == '/')
	{
		return Token{TokenKind::TokenSlash, m_position++, "/"};
	}
	else if (current() == '\0')
	{
		return Token{TokenKind::TokenEof, m_position++, "\0"};
	}

	return Token{};
}



