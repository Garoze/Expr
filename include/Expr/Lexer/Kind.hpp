#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

enum class kind_t
{
    __EOF = 0,

    LPAREN,
    RPAREN,

    PLUS,
    MINUS,
    SLASH,
    STAR,
    PERCENTAGE,
    CARROT,

    NUMBERLIT,
    ERROR,
};

const std::unordered_map<char, kind_t> char_to_kind = {
    { '(', kind_t::LPAREN },     { ')', kind_t::RPAREN }, { '+', kind_t::PLUS },
    { '-', kind_t::MINUS },      { '/', kind_t::SLASH },  { '*', kind_t::STAR },
    { '%', kind_t::PERCENTAGE }, { '^', kind_t::CARROT },
};

class Kind
{
public:
    Kind(char);
    Kind(kind_t);

    [[nodiscard]] auto raw() const -> kind_t;
    [[nodiscard]] auto as_string() const -> std::string;

private:
    kind_t m_kind;
};
