#include "Lexer/Kind.hpp"

Kind::Kind(kind_t kind)
    : m_kind(kind)
{}

auto Kind::raw() const -> kind_t
{
    return m_kind;
}

auto Kind::as_string() const -> std::string
{
    return KIND_TO_STR.at(m_kind);
}
