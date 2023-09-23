#pragma once

#include <cstddef>
#include <cstdint>
#include <cwchar>
#include <optional>
#include <vector>

#include "Lexer/Kind.hpp"
#include "Lexer/Token.hpp"

class Parser
{
public:
    Parser();
    Parser(std::vector<Token>&);

    auto Parse() -> void;

private:
    auto step() -> void;
    auto chop() -> std::optional<Token>;
    auto expect(kind_t) const -> bool;

    auto look_ahead(std::size_t = 0) const -> std::optional<Token>;

private:
    std::size_t m_index;
    std::vector<Token> m_tokens;
};
