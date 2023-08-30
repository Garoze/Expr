#include <cstdlib>
#include <format>
#include <iostream>
#include <string>
#include <variant>

#include "Lexer/Kind.hpp"
#include "Lexer/Location.hpp"
#include "Lexer/Token.hpp"

#include "Print.hpp"

Token::Token(kind_t kind, value_t value, std::size_t line, std::size_t col)
    : m_kind(kind)
    , m_value(value)
    , m_location(line, col)
{}

auto Token::kind() const -> kind_t
{
    return m_kind.raw();
}

auto Token::value() const -> Value
{
    return m_value;
}

auto Token::location() const -> Location
{
    return m_location;
}

auto Token::debug(bool debug) const -> void
{
    if (debug)
    {
        expr::print("( {} \"{}\" {} {} )\n", m_kind.as_string(),
                    m_value.as_string(), m_location.line(),
                    m_location.column());
    }
    else
    {
        expr::print("( {} \"{}\" )\n", m_kind.as_string(), m_value.as_string());
    }
}
