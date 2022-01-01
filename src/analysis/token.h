#pragma once
#include <string_view>

enum class TokenKind : int
{
	TokenEof,
	TokenNumber,
	TokenIdentifier,
	TokenPlus,
	TokenMinus,
	TokenStar,
	TokenSlash,
	TokenError
};

class Token
{
public:
	Token() = default;
	Token(TokenKind kind, int position, std::string_view value);
	TokenKind kind() const;
	std::string_view value() const;
	int position() const;

private:
	TokenKind m_kind{TokenKind::TokenError};
	std::string_view m_value{};
	int m_position{0};
};