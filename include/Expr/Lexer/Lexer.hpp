#pragma once

#include <optional>
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
    auto step() -> void;
    auto peek(std::size_t) const -> std::optional<char>;
    auto is_space() -> void;
    auto push_token(Token) -> void;

    auto lex_numbers() -> Token;
    auto lex_literals() -> Token;

private:
    std::size_t m_line;
    std::size_t m_index;
    std::string m_source;
    std::vector<Token> m_tokens;
};
