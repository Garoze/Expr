#include <cstddef>
#include <cstdlib>
#include <format>
#include <iostream>
#include <stack>
#include <string>

#include "Lexer/Kind.hpp"
#include "Lexer/Lexer.hpp"
#include "Lexer/Token.hpp"

#include "Print.hpp"

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

enum class State
{
    START,
    LEX_NUMBERS,
    FINISH,
};

auto Lexer::lex_numbers() -> Token
{
    State s = State::START;

    while (s != State::FINISH)
    {
        switch (s)
        {
            case State::START: {
                switch (char c = current_char())
                {
                    case '0' ... '9':
                        s = State::LEX_NUMBERS;
                        break;
                    default:
                        s = State::FINISH;
                        break;
                }
            }
            break;
            case State::LEX_NUMBERS: {
                switch (char c = current_char())
                {
                    case '0': {
                        if (peek(1).value() == 'x')
                        {
                            expr::print("Lexing a hex number\n");
                            // TODO: change the state to the lex_hex impl
                            s = State::FINISH;
                        }
                    }
                    case '1' ... '9':
                        step();
                        expr::print("Number: {}\n", c);
                        break;
                    default:
                        s = State::FINISH;
                        break;
                }
            }
            break;

            case State::FINISH:
                s = State::FINISH;
                break;

            default:
                break;
        }
    }

    auto err =
        std::format("[Lexer] - Invalid token with value: {}", current_char());

    // TODO: find a better way to deal with errors
    return Token(kind_t::ERROR, err, m_line, m_index);
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
            case '(':
            case ')':
                return lex_literals();
                break;

            default:
                step();
                expr::print("[Lexer] - Line: {} Column: {} -> {}\n", m_line,
                            m_index, c);
                break;
        }
    }

    return Token(kind_t::ENDOFFILE, {}, m_line, m_index);
}
