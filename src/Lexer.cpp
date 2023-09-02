#include <charconv>
#include <cstddef>
#include <cstdlib>
#include <format>
#include <iostream>
#include <stack>
#include <string>
#include <string_view>

#include "Lexer/Kind.hpp"
#include "Lexer/Lexer.hpp"
#include "Lexer/Token.hpp"

#include "Print.hpp"

Lexer::Lexer()
    : m_line(1)
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

auto Lexer::peek(std::size_t n = 0) const -> std::optional<char>
{
    if ((m_index + n) < m_source.length())
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

// TODO: find a way to deal with float numbers
auto Lexer::lex_numbers() -> Token
{
    std::size_t start{ m_index };

    while (!is_empty() && std::isdigit(current_char()))
    {
        step();
    }

    int value;
    auto [_, err] = std::from_chars(m_source.data() + start,
                                    m_source.data() + m_index, value);

    return Token(kind_t::NUMBER, value, m_line, m_index);
}

auto Lexer::lex_literals() -> Token
{
    switch (char c = current_char())
    {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
        case '(':
        case ')':
            step();
            return Token(LITERAL_TO_KIND.at(c), std::string(1, c), m_line,
                         m_index);
            break;

        default:
            expr::print("Invalid Literal on Line: {} and Column: {} -> {}\n",
                        m_line, m_index, c);
            break;
    }

    // TODO: find a better way to deal with errors
    return Token(kind_t::ERROR, "Invalid token from lex_literals", m_line,
                 m_index);
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
            case '(':
            case ')':
                return lex_literals();
                break;

            default:
                expr::print("[Lexer] - Line: {} Column: {} -> \"{}\"\n", m_line,
                            m_index, c);

                step();
                break;
        }
    }

    return Token(kind_t::ENDOFFILE, {}, m_line, m_index);
}
