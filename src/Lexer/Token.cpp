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
        if (m_kind.raw() == kind_t::NUMBER)
        {
            expr::print("( {} \"{:.2f}\" )\n", m_kind.as_string(),
                        std::get<double>(m_value.raw()));
        }
        else
        {
            expr::print("( {} \"{}\" )\n", m_kind.as_string(),
                        m_value.as_string());
        }
    }
}

auto Token::as_string() const -> std::string
{
    if (m_kind.raw() == kind_t::NUMBER)
    {

        return std::format("( {} \"{:.2f}\" )\n", m_kind.as_string(),
                           std::get<double>(m_value.raw()));
    }
    else
    {
        return std::format("( {} \"{}\" )\n", m_kind.as_string(),
                           m_value.as_string());
    }
}
