#include <string>
#include <string_view>
#include <unordered_map>

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
    return kind_as_string.at(m_kind);
}
