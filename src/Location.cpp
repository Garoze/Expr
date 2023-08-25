#include <iostream>

#include "fmt/core.h"

#include "Lexer/Location.hpp"

Location::Location(std::size_t line, std::size_t col)
    : m_line(line)
    , m_column(col)
{}

auto Location::line() const -> std::size_t
{
    return m_line;
}
auto Location::column() const -> std::size_t
{
    return m_column;
}

auto Location::as_string() const -> std::string
{
    return fmt::format("Line: {} Col: {}", m_line, m_column);
}
