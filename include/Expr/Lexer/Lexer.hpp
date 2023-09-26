#pragma once

#include <optional>
#include <string>
#include <vector>

#include "Token.hpp"

class Lexer
{
public:
    Lexer();

    auto lex_line(std::string, bool = false) -> std::vector<Token>;

private:
    [[nodiscard]] auto is_empty() const -> bool;
    [[nodiscard]] auto current_char() const -> char;
    [[nodiscard]] auto next_token() -> Token;

    [[nodiscard]] auto sanitize_input(std::string) -> std::string;

private:
    auto step() -> void;
    auto is_space() -> void;
    auto push_token(Token) -> void;

    [[nodiscard]] auto peek(std::size_t) const -> std::optional<char>;

private:
    [[nodiscard]] auto lex_base() -> double;
    [[nodiscard]] auto lex_numbers() -> Token;
    [[nodiscard]] auto lex_operators() -> Token;
    [[nodiscard]] auto lex_separators() -> Token;

private:
    std::size_t m_line;
    std::size_t m_index;
    std::string m_source;
    std::vector<Token> m_tokens;
};
