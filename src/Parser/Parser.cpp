#include <algorithm>
#include <cstdint>
#include <tuple>
#include <unordered_map>

#include "fmt/core.h"

#include "Lexer/Kind.hpp"

#include "Parser/BinaryExpression.hpp"
#include "Parser/NumberLiteral.hpp"
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

auto Parser::Parse() -> void
{
    parse_expr();
}

// Expr -> Term { + | - Term }+
auto Parser::parse_expr() -> Expression
{
    fmt::print("Parsing an expression -> current: {}",
               look_ahead()->as_string());
    auto lhs = parse_term();

    while (look_ahead()->kind().raw() == kind_t::PLUS ||
           look_ahead()->kind().raw() == kind_t::MINUS)
    {
        auto op = look_ahead().value();
        step();
        auto rhs = parse_term();

        return BinaryExpression{ lhs, rhs, op.as_string() };
    }

    return lhs;
}

// Term -> Factor * Term | Factor / Term | Factor
auto Parser::parse_term() -> Expression
{
    fmt::print("Parsing an term -> current: {}", look_ahead()->as_string());
    auto lhs = parse_factor();

    while (look_ahead()->kind().raw() == kind_t::STAR ||
           look_ahead()->kind().raw() == kind_t::SLASH)
    {
        auto op = look_ahead().value();
        step();
        auto rhs = parse_term();

        return BinaryExpression{ lhs, rhs, op.as_string() };
    }

    return lhs;
}

// Factor -> NUMBERLIT
auto Parser::parse_factor() -> Expression
{
    fmt::print("Parsing an factor -> current: {}", look_ahead()->as_string());
    if (!expect(kind_t::NUMBERLIT))
    {
        fmt::print("Expected a NumberLiteral and got {}\n",
                   look_ahead()->kind().as_string());
        std::exit(1);
    }

    auto token = look_ahead().value();
    step();

    return NumberLiteral{ std::get<double>(token.value().raw()) };
}
