#pragma once

#include <stack>
#include <string>
#include <vector>

#include "Token.hpp"

class Lexer
{
public:
    Lexer();

    auto lex_line(std::string) -> void;

public:
    [[nodiscard]] auto is_empty() const -> bool;
    [[nodiscard]] auto current_char() const -> char;
    [[nodiscard]] auto next_token() -> Token;

private:
    auto step() -> bool;
    auto is_space() -> void;
    auto push_token(Token) -> void;

private:
    std::size_t m_line;
    std::size_t m_index;
    std::string m_source;
    std::vector<Token> m_tokens;
};
