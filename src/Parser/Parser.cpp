#include <algorithm>
#include <cstdint>
#include <tuple>
#include <unordered_map>

#include "Lexer/Kind.hpp"
#include "Parser/Expression.hpp"
#include "Parser/Parser.hpp"
#include "Print.hpp"

std::unordered_map<kind_t, Precedence> KIND_PRECEDENCE = {
    { kind_t::ADDITION, Precedence::Term },
    { kind_t::SUBTRACTION, Precedence::Term },
    { kind_t::MULTIPLICATION, Precedence::Mult },
    { kind_t::DIVISION, Precedence::Div },
    { kind_t::POWER, Precedence::Power },
};

Parser::Parser()
    : m_index(0)
{}

Parser::Parser(std::vector<Token>& tokens)
    : m_index(0)
    , m_tokens(std::move(tokens))
{}

auto Parser::step() -> void
{
    if ((m_index + 1) <= m_tokens.size())
    {
        m_index++;
    }
}

auto Parser::chop() -> std::optional<Token>
{
    if ((m_index + 1) <= m_tokens.size())
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
    if ((m_index + pos) <= m_tokens.size())
    {
        return m_tokens.at(m_index);
    }

    return {};
}

auto Parser::Parse() -> void
{
    while (look_ahead()->kind() != kind_t::ENDOFFILE)
    {
        switch (look_ahead()->kind())
        {
            default:
                expr::print("Unimplemented token {}",
                            look_ahead()->as_string());
                break;
        }
    }
}

auto Parser::parse_expression(Precedence current_precedence) -> Expression
{
    Expression left = parse_prefix_expr();
    auto op = look_ahead().value();
    Precedence next_precedence = KIND_PRECEDENCE.at(look_ahead()->kind());

    while (next_precedence != Precedence::Normal)
    {
        if (current_precedence >= next_precedence)
        {
            break;
        }
        else
        {
            step();
            left = parse_infix_expr(op, left);
            op = look_ahead().value();
            next_precedence = KIND_PRECEDENCE.at(look_ahead()->kind());
        }
    }

    return left;
}

auto Parser::parse_infix_expr(Token op, Expression left) -> Expression
{
    Expression expr;
    AST_kind kind;

    switch (op.kind())
    {
        case kind_t::ADDITION:
        case kind_t::SUBTRACTION:
        case kind_t::MULTIPLICATION:
        case kind_t::DIVISION:
        case kind_t::POWER:
            break;

        default:
            break;
    }

    return {};
}

auto Parser::parse_number() -> NumberLiteral
{
    auto current = chop()->value();
    return NumberLiteral(std::get<double>(current.value()));
}

auto Parser::parse_prefix_expr() -> Expression
{
    Expression expr;

    switch (look_ahead()->kind())
    {
        case kind_t::NUMBER:
            expr = parse_number();
            break;

        case kind_t::OPENPAREN:
            step();
            expr = parse_expression(Precedence::Normal);
            switch (look_ahead()->kind())
            {
                case kind_t::OPENPAREN:
                    step();
                    break;

                default:
                    expr::print("Something went wrong!\n");
                    break;
            }
            break;

        default:
            break;
    }

    return expr;
}
