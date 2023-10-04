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

class Kind
{
public:
    Kind(kind_t);

    [[nodiscard]] auto raw() const -> kind_t;
    [[nodiscard]] auto as_string() const -> std::string;

private:
    kind_t m_kind;
};
