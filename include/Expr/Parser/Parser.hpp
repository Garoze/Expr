#pragma once

#include <cstddef>
#include <cstdint>
#include <cwchar>
#include <memory>
#include <optional>
#include <vector>

#include "Lexer/Kind.hpp"
#include "Lexer/Token.hpp"

#include "Parser/Expression.hpp"

class Parser
{
public:
    Parser();
    Parser(std::vector<Token>&);

    auto Parse(bool = false) -> void;

    auto parse_expr() -> std::unique_ptr<Expression>;
    auto parse_term() -> std::unique_ptr<Expression>;
    auto parse_factor() -> std::unique_ptr<Expression>;

private:
    auto step() -> void;
    auto chop() -> std::optional<Token>;
    auto match(kind_t) -> bool;
    auto match(kind_t, std::string) -> bool;
    auto expect(kind_t) -> std::optional<Token>;

    auto on_range(std::size_t) const -> bool;
    auto look_ahead(std::size_t = 0) const -> std::optional<Token>;

    auto eval_expr(Expression) -> double;

    auto is_empty() const -> bool;

private:
    std::size_t m_index;
    std::vector<Token> m_tokens;
};
