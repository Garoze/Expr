#include <algorithm>

#include "Lexer/Kind.hpp"
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

auto Parser::parse_expression() -> void
{}

auto Parser::parse_infix_expr() -> void
{}

auto Parser::parse_prefix_expr() -> void
{}
