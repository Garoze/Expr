#include "fmt/core.h"

#include "Parser/BinaryExpression.hpp"
#include "Parser/NumberLiteral.hpp"
#include "Parser/Visitor.hpp"

#define SPACE(n) fmt::format("{:>{}}", "", (n) + 1);

auto Printer::visit(const NumberLiteral& num, int depth) -> void
{
    auto space = SPACE(depth);
    fmt::print("{}Lit: {}\n", space, num.value());
}

auto Printer::visit(const BinaryExpression& expr, int depth) -> void
{
    auto space = SPACE(depth);
    fmt::print("{}Op: {}\n", space, depth, expr.op());

    expr.lhs()->visit(*this, depth + 1);
    expr.rhs()->visit(*this, depth + 1);
}
