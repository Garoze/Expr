#include <algorithm>
#include <cstdint>
#include <memory>
#include <tuple>
#include <unordered_map>

#include "Parser/Evaluator.hpp"
#include "fmt/core.h"

#include "Lexer/Kind.hpp"

#include "Parser/BinaryExpr.hpp"
#include "Parser/NumberLit.hpp"
#include "Parser/Parser.hpp"
#include "Parser/Printer.hpp"

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
    Printer p;
    auto expr = parse_expr();
    expr->visit(p);

    Evaluator e;
    auto result = expr->eval(e);

    fmt::print("Result: {}\n", result);
}

// Expr -> Term { + | - Term }+
auto Parser::parse_expr() -> std::unique_ptr<Expression>
{
    auto lhs = parse_term();

    while (look_ahead()->kind().raw() == kind_t::PLUS ||
           look_ahead()->kind().raw() == kind_t::MINUS)
    {
        auto op = look_ahead().value();
        step();
        auto rhs = parse_term();

        lhs = std::make_unique<BinaryExpr>(
            std::move(lhs), std::move(rhs),
            std::get<std::string>(op.value().raw()));
    }

    return lhs;
}

// Term -> Factor * Term | Factor / Term | Factor
auto Parser::parse_term() -> std::unique_ptr<Expression>
{
    auto lhs = parse_factor();

    while (look_ahead()->kind().raw() == kind_t::STAR ||
           look_ahead()->kind().raw() == kind_t::SLASH)
    {
        auto op = look_ahead().value();
        step();
        auto rhs = parse_term();

        lhs = std::make_unique<BinaryExpr>(
            std::move(lhs), std::move(rhs),
            std::get<std::string>(op.value().raw()));
    }

    return lhs;
}

// Factor -> NUMBERLIT
auto Parser::parse_factor() -> std::unique_ptr<Expression>
{
    if (!expect(kind_t::NUMBERLIT))
    {
        fmt::print("Expected a NumberLiteral and got {}\n",
                   look_ahead()->kind().as_string());
        std::exit(1);
    }

    auto token = look_ahead().value();
    step();

    return std::make_unique<NumberLit>(std::get<double>(token.value().raw()));
}
