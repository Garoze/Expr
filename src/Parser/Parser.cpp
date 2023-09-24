#include <algorithm>
#include <cstdint>
#include <tuple>
#include <unordered_map>

#include "fmt/core.h"

#include "Lexer/Kind.hpp"
#include "Parser/Parser.hpp"

Parser::Parser()
    : m_index(0)
{}

Parser::Parser(std::vector<Token>& tokens)
    : m_index(0)
    , m_tokens(std::move(tokens))
{}

auto Parser::on_range(std::size_t count = 0) const -> bool
{
    return ((m_index + count) <= m_tokens.size());
}

auto Parser::step() -> void
{
    if (on_range(1))
    {
        m_index++;
    }
}

auto Parser::chop() -> std::optional<Token>
{
    if (on_range(1))
    {
        return m_tokens.at(m_index++);
    }

    return {};
}

auto Parser::expect(kind_t kind) const -> bool
{
    return m_tokens.at(m_index).kind() == kind;
}

auto Parser::look_ahead(std::size_t pos) const -> std::optional<Token>
{
    if (on_range(pos))
    {
        return m_tokens.at(m_index);
    }

    return {};
}

auto Parser::Parse() -> void
{
    while (look_ahead()->kind() != kind_t::__EOF)
    {
        switch (look_ahead()->kind())
        {
            default:
                fmt::print("Unimplemented token {}", look_ahead()->as_string());
                break;
        }
    }
}
