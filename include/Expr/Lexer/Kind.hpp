#pragma once

#include <string>
#include <unordered_map>

enum class kind_t
{
    NUMBER,
    MULTIPLICATION,
    DIVISION,
    ADDITION,
    SUBTRACTION,
    POWER,
    MODULUS,
    OPENPAREN,
    CLOSEPAREN,
    ERROR,
    ENDOFFILE,
};

const std::unordered_map<kind_t, std::string> KIND_TO_STR = {
    { kind_t::NUMBER, "Number" },
    { kind_t::MULTIPLICATION, "Multiplication" },
    { kind_t::DIVISION, "Division" },
    { kind_t::ADDITION, "Addition" },
    { kind_t::SUBTRACTION, "Subtraction" },
    { kind_t::OPENPAREN, "Openparen" },
    { kind_t::CLOSEPAREN, "Closeparen" },
    { kind_t::ERROR, "Error" },
    { kind_t::ENDOFFILE, "EOF" },
};

const std::unordered_map<char, kind_t> LITERAL_TO_KIND = {
    { '+', kind_t::ADDITION },       { '-', kind_t::SUBTRACTION },
    { '*', kind_t::MULTIPLICATION }, { '/', kind_t::DIVISION },
    { '%', kind_t::MODULUS },        { '^', kind_t::ADDITION },
    { '(', kind_t::OPENPAREN },      { ')', kind_t::CLOSEPAREN },
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
