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
