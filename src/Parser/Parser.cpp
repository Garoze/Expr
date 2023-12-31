#include <algorithm>
#include <atomic>
#include <cstdint>
#include <memory>
#include <unordered_map>

#include "fmt/core.h"

#include "Lexer/Kind.hpp"

#include "Parser/AssignExpr.hpp"
#include "Parser/BinaryExpr.hpp"
#include "Parser/Evaluator.hpp"
#include "Parser/IdentifierExpr.hpp"
#include "Parser/NumberLit.hpp"
#include "Parser/Parser.hpp"
#include "Parser/Printer.hpp"
#include "Parser/ProgramExpr.hpp"

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

auto Parser::match(kind_t kind) -> bool
{
    if (look_ahead()->kind().raw() != kind)
    {
        fmt::print("[Parser::match] Pos: {} - Expected `{}` got `{}`!\n",
                   m_index, kind_as_string.at(kind),
                   look_ahead()->kind().as_string());

        std::exit(1);
    }

    step();
    return true;
}

auto Parser::match(kind_t kind, std::string err) -> bool
{
    if (look_ahead()->kind().raw() != kind)
    {
        fmt::print("[Parser::match] Pos: {} - Err: {}\n", m_index, err);

        std::exit(1);
    }

    step();
    return true;
}

auto Parser::expect(kind_t kind) -> std::optional<Token>
{
    auto token = m_tokens.at(m_index);

    if (match(kind))
    {
        return token;
    }

    return {};
}

auto Parser::look_ahead(std::size_t pos) const -> std::optional<Token>
{
    if (on_range(pos))
    {
        return m_tokens.at(m_index);
    }

    return {};
}

auto Parser::is_empty() const -> bool
{
    return m_index >= m_tokens.size();
}

auto Parser::Parse(bool debug) -> void
{
    ProgramExpr prog;
    Printer printer;
    Evaluator evaluator;

    while (look_ahead()->kind().raw() != kind_t::__EOF)
    {
        auto expr = parse_expr();
        prog.body.push_back(std::move(expr));
    }

    if (debug)
        prog.visit(printer);

    prog.visit(evaluator);
    fmt::print("Result: {:.2f}\n", evaluator.value());
}

auto Parser::parse_expr() -> std::unique_ptr<Expression>
{
    auto lhs = parse_term();

    while (look_ahead()->kind().raw() == kind_t::PLUS ||
           look_ahead()->kind().raw() == kind_t::MINUS)
    {
        auto op = look_ahead().value();
        step();
        auto rhs = parse_term();

        lhs = std::make_unique<BinaryExpression>(
            std::move(lhs), std::move(rhs),
            std::get<std::string>(op.value().raw()));
    }

    return lhs;
}

auto Parser::parse_term() -> std::unique_ptr<Expression>
{
    auto lhs = parse_factor();

    while (look_ahead()->kind().raw() == kind_t::STAR ||
           look_ahead()->kind().raw() == kind_t::SLASH)
    {
        auto op = look_ahead().value();
        step();
        auto rhs = parse_term();

        lhs = std::make_unique<BinaryExpression>(
            std::move(lhs), std::move(rhs),
            std::get<std::string>(op.value().raw()));
    }

    return lhs;
}

auto Parser::parse_factor() -> std::unique_ptr<Expression>
{
    switch (look_ahead()->kind().raw())
    {
        case kind_t::NUMBERLIT:
        {
            auto token = expect(kind_t::NUMBERLIT).value();

            return std::make_unique<NumberLiteral>(
                std::get<double>(token.value().raw()));
        }
        break;

        case kind_t::IDENTIFIER:
        {
            auto token = expect(kind_t::IDENTIFIER).value();

            auto identifier = std::make_unique<IdentifierExpr>(
                std::get<std::string>(token.value().raw()));

            switch (look_ahead()->kind().raw())
            {
                case kind_t::EQUALS:
                {
                    match(kind_t::EQUALS);
                    auto expr = parse_expr();
                    match(kind_t::SEMI);

                    return std::make_unique<AssignExpression>(
                        std::move(expr), std::move(identifier));
                }
                break;

                default:
                    return identifier;
                    break;
            }
        }
        break;

        case kind_t::LPAREN:
        {
            match(kind_t::LPAREN);
            auto expr = parse_expr();
            match(kind_t::RPAREN);

            return expr;
        }
        break;

        case kind_t::__EOF:
            fmt::print("[parser] - Unfinished expression at position: `{}`\n",
                       m_index);
            std::exit(1);
            break;

        default:
        {
            fmt::print("[parse_factor] -> Got something else than a "
                       "`NUMBERLIT`, `LPAREN` or `IDENTIFIER` at {} -> {}\n",
                       m_index, look_ahead()->as_string());
            std::exit(1);
        }
        break;
    }
}
