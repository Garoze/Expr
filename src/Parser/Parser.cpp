#include <algorithm>
#include <tuple>

#include "Lexer/Kind.hpp"
#include "Parser/Expression.hpp"
#include "Parser/Parser.hpp"
#include "Print.hpp"

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

auto Parser::parse_expression() -> Expression
{
    return {};
}

auto Parser::parse_infix_expr() -> void
{}

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
            expr = parse_expression();
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