#include <string>
#include <string_view>
#include <unordered_map>

#include "Lexer/Kind.hpp"

const std::unordered_map<kind_t, std::string> kind_as_string = {
    { kind_t::TOKEN_NUMBER, "Number" },
    { kind_t::TOKEN_ERROR, "Number" },
};

Kind::Kind(char kind)
    : m_kind(static_cast<kind_t>(kind))
{}

Kind::Kind(kind_t kind)
    : m_kind(kind)
{}

auto Kind::raw() const -> kind_t
{
    return m_kind;
}

auto Kind::as_int() const -> int
{
    return static_cast<int>(m_kind);
}

auto Kind::as_int(kind_t kind) const -> int
{
    return static_cast<int>(kind);
}

auto Kind::as_string() const -> std::string
{
    if (as_int(m_kind) >= 128)
    {
        return kind_as_string.at(m_kind);
    }
    else
    {
        return std::string(1, as_int(m_kind));
    }
}
