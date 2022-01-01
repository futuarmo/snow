#include "token.h"

Token::Token(TokenKind kind, int position, std::string_view value) : m_kind(kind), m_value(value), m_position(position)
{
}

TokenKind Token::kind() const
{
	return m_kind;
}

std::string_view Token::value() const
{
	return m_value;
}

int Token::position() const
{
	return m_position;
}
