#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

#include "Lexer/Lexer.hpp"
#include "Lexer/Token.hpp"
#include "fmt/core.h"

Lexer::Lexer()
    : m_line(0)
    , m_index(0)
{}

auto Lexer::lex_line(std::string l) -> void
{
    m_source = l;

    while (auto token = next_token())
    {
        if (token.kind() == kind_t::ENDOFFILE)
            break;

        token.debug();
    }

    m_source = "";
    m_index = 0;
}

auto Lexer::step() -> bool
{
    if ((m_index + 1) > m_source.length())
    {
        return false;
    }

    m_index++;
    return true;
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
                step();
                return Token(kind_t::NUMBER, (c - '0'), m_line, m_index);
                break;

            case '*':
                step();
                return Token(kind_t::MULTIPLICATION, std::string(1, c), m_line,
                             m_index);
                break;
            case '/':
                step();
                return Token(kind_t::DIVISION, std::string(1, c), m_line,
                             m_index);
                break;
            case '+':
                step();
                return Token(kind_t::ADDITION, std::string(1, c), m_line,
                             m_index);
                break;
            case '-':
                step();
                return Token(kind_t::SUBTRACTION, std::string(1, c), m_line,
                             m_index);
                break;

            case '(':
                step();
                return Token(kind_t::OPENPAREN, std::string(1, c), m_line,
                             m_index);
                break;

            case ')':
                step();
                return Token(kind_t::CLOSEPAREN, std::string(1, c), m_line,
                             m_index);
                break;

            default:
                step();
                fmt::print("[Lexer] - Line: {} Column: {} Current: {}\n",
                           m_line, m_index, c);
                break;
        }
    }

    return Token(kind_t::ENDOFFILE, {}, m_line, m_index);
}
