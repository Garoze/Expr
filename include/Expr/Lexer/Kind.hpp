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
    OPENPAREN,
    CLOSEPAREN,
    ENDOFFILE,
};

const std::unordered_map<kind_t, std::string> KIND_STR = {
    { kind_t::NUMBER, "Number" },
    { kind_t::MULTIPLICATION, "Multiplication" },
    { kind_t::DIVISION, "Division" },
    { kind_t::ADDITION, "Addition" },
    { kind_t::SUBTRACTION, "Subtraction" },
    { kind_t::OPENPAREN, "Openparen" },
    { kind_t::CLOSEPAREN, "Closeparen" },
    { kind_t::ENDOFFILE, "EOF" },
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
