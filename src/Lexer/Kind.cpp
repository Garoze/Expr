#include <string>
#include <string_view>
#include <unordered_map>

#include "Lexer/Kind.hpp"

const std::unordered_map<kind_t, std::string> kind_as_string = {
    { kind_t::LPAREN, "LeftParen" },
    { kind_t::RPAREN, "RightParen" },
    { kind_t::PLUS, "Plus" },
    { kind_t::MINUS, "Minus" },
    { kind_t::SLASH, "Slash" },
    { kind_t::STAR, "Star" },
    { kind_t::PERCENTAGE, "Percentage" },
    { kind_t::CARROT, "Carrot" },
    { kind_t::NUMBERLIT, "NumberLit" },
    { kind_t::ERROR, "Error" },
};

Kind::Kind(kind_t kind)
    : m_kind(kind)
{}

auto Kind::raw() const -> kind_t
{
    return m_kind;
}

auto Kind::as_string() const -> std::string
{
    return kind_as_string.at(m_kind);
}
