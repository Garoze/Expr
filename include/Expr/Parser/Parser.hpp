#pragma once

#include <cstddef>
#include <cstdint>
#include <cwchar>
#include <optional>
#include <vector>

#include "Lexer/Kind.hpp"
#include "Lexer/Token.hpp"

#include "Parser/Expression.hpp"

enum class Precendence
{
    prec0,
    prec1,
    __count,
};

class Parser
{
public:
    Parser();
    Parser(std::vector<Token>&);

    auto Parse() -> void;

    auto parse_expr(Precendence = Precendence::prec0) -> Expression;
    auto parse_primary() -> Expression;

private:
    auto step() -> void;
    auto chop() -> std::optional<Token>;
    auto expect(kind_t) const -> bool;

    auto on_range(std::size_t) const -> bool;
    auto look_ahead(std::size_t = 0) const -> std::optional<Token>;

private:
    std::size_t m_index;
    std::vector<Token> m_tokens;
};
