#include <algorithm>
#include <cstdint>
#include <tuple>
#include <unordered_map>

#include "fmt/core.h"

#include "Lexer/Kind.hpp"

#include "Parser/BinaryExpression.hpp"
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

auto Parser::expect(char c) -> bool
{
    return m_tokens.at(m_index).kind().as_int() == c;
}

auto Parser::expect(kind_t kind) const -> bool
{
    return m_tokens.at(m_index).kind().raw() == kind;
}

auto Parser::look_ahead(std::size_t pos) const -> std::optional<Token>
{
    if (on_range(pos))
    {
        return m_tokens.at(m_index);
    }

    return {};
}

auto Parser::parse_expr(Precendence p) -> Expression
{
    if (p > Precendence::__count)
    {
        return parse_primary();
    }

    auto p_as_int = static_cast<int>(p);

    auto lhs = parse_expr(static_cast<Precendence>(p_as_int + 1));

    if (auto op = look_ahead().value())
    {
        auto rhs = parse_expr(p);

        return BinaryExpression{ lhs, rhs, op.as_string() };
    }

    return lhs;
}

auto Parser::parse_primary() -> Expression
{
    if (auto token = look_ahead().value())
    {
        switch (token.kind().as_int())
        {
            case '(':
            {
                auto expr = parse_expr();
                step();
                expect(')');
                return expr;
            }
            break;

            case ')':
                fmt::print("No primary expression starts with ')'\n");
                break;
        }
    }

    fmt::print(
        "Expected primary expression but reached the end of the input\n");
    std::exit(1);
}

auto Parser::Parse() -> void
{
    parse_primary();
}
