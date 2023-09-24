#include <algorithm>
#include <cctype>
#include <charconv>
#include <cstddef>
#include <cstdlib>
#include <format>
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>

#include "fmt/core.h"

#include "Lexer/Kind.hpp"
#include "Lexer/Lexer.hpp"
#include "Lexer/Token.hpp"

Lexer::Lexer()
    : m_line(1)
    , m_index(0)
{}

auto Lexer::sanitize_input(std::string s) -> std::string
{
    std::transform(
        s.begin(), s.end(), s.begin(),
        [](unsigned char c) -> unsigned char { return std::toupper(c); });

    return s;
}

auto Lexer::lex_line(std::string line) -> void
{
    m_source = sanitize_input(line);

    while (auto token = next_token())
    {
        if (token.kind() == kind_t::__EOF)
            break;

        token.debug();
    }

    m_source = "";
    m_index = 0;
}

auto Lexer::step() -> void
{
    if ((m_index + 1) <= m_source.length())
    {
        m_index++;
    }
}

auto Lexer::peek(std::size_t n = 0) const -> std::optional<char>
{
    if ((m_index + n) <= m_source.length())
    {
        return m_source.at(m_index + n);
    }

    return {};
}

auto Lexer::is_space() -> void
{
    if (current_char() == '\n')
    {
        m_line++;
    }

    step();
}

auto Lexer::is_empty() const -> bool
{
    return m_index >= m_source.length();
}

auto Lexer::current_char() const -> char
{
    return m_source.at(m_index);
}

auto Lexer::push_token(Token t) -> void
{
    m_tokens.push_back(t);
}

std::unordered_map<char, int> char_to_digit = {
    { '0', 0 },  { '1', 1 },  { '2', 2 },  { '3', 3 },
    { '4', 4 },  { '5', 5 },  { '6', 6 },  { '7', 7 },
    { '8', 8 },  { '9', 9 },  { 'a', 10 }, { 'b', 11 },
    { 'c', 12 }, { 'd', 13 }, { 'e', 14 }, { 'f', 15 },
};

auto Lexer::lex_base() -> double
{
    double base{ 10 };

    switch (current_char())
    {
        case '0':
            step();
            switch (current_char())
            {
                case 'x':
                    step();
                    base = 16;
                    break;
                case 'b':
                    step();
                    base = 2;
                    break;
                default:
                    base = 8;
                    break;
            }
            break;
    }

    return base;
}

auto Lexer::lex_numbers() -> Token
{
    double value{ 0 };
    double base = lex_base();

    while (!is_empty() &&
           (std::isdigit(current_char()) || std::isxdigit(current_char())))
    {
        double digit = char_to_digit.at(current_char());

        if (digit == 0 && is_empty())
        {
            break;
        }

        if (digit >= base)
        {
            auto err = fmt::format(
                "Syntax error -> Digit '{}' out of range for base {}\n", digit,
                base);

            return Token(kind_t::TOKEN_ERROR, err, m_line, m_index);
            digit = 0;
        }

        if (value > (std::numeric_limits<double>::max() / base))
        {
            auto err =
                fmt::format("Syntax error -> Integer literal overflow\n");

            return Token(kind_t::TOKEN_ERROR, err, m_line, m_index);

            while (isdigit(current_char()))
            {
                step();
            }
            value = 0;
            break;
        }

        value = (value * base) + digit;
        step();
    }

    return Token(kind_t::TOKEN_NUMBER, value, m_line, m_index);
}

auto Lexer::lex_operators() -> Token
{
    switch (char c = current_char())
    {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
            step();
            return Token(c, {}, m_line, m_index);
            break;

        default:
            fmt::print("Invalid Operator on Line: {} and Column: {} -> {}\n",
                       m_line, m_index, c);
            break;
    }

    return Token(kind_t::TOKEN_ERROR, "Invalid token from lex_operators",
                 m_line, m_index);
}

auto Lexer::lex_separators() -> Token
{
    switch (char c = current_char())
    {
        case '(':
        case ')':
            step();
            return Token(c, {}, m_line, m_index);
            break;

        default:
            fmt::print("Invalid Separator on Line: {} and Column: {} -> {}\n",
                       m_line, m_index, c);
            break;
    }

    return Token(kind_t::TOKEN_ERROR, "Invalid token from lex_separators",
                 m_line, m_index);
}

auto Lexer::next_token() -> Token
{
    while (!is_empty())
    {
        switch (char c = current_char())
        {
            case ' ':
            case '\n':
            case '\r':
            case '\t':
                is_space();
                break;

            case '0' ... '9':
                return lex_numbers();
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '%':
                return lex_operators();
                break;

            case '(':
            case ')':
                return lex_separators();
                break;

            default:
                fmt::print("[Lexer] - Line: {} Column: {} -> \"{}\"\n", m_line,
                           m_index, c);

                step();
                break;
        }
    }

    return Token(kind_t::__EOF, {}, m_line, m_index);
}
