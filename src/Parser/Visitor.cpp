#include "fmt/core.h"

#include "Parser/BinaryExpression.hpp"
#include "Parser/NumberLiteral.hpp"
#include "Parser/Visitor.hpp"

#define SPACE(n) fmt::format("{:>{}}", "", (n) + 1)

auto Printer::makePrefix(int depth, bool last) -> std::string
{
    auto space = SPACE(depth);
    return space + (last ? "└──" : "├──");
}

auto Printer::visit(const NumberLiteral& num, int depth, bool last) -> void
{
    auto prefix = makePrefix(depth, last);
    fmt::print("{}Lit: {}\n", prefix, num.value());
}

auto Printer::visit(const BinaryExpression& expr, int depth, bool) -> void
{
    fmt::print("{}Op: {}\n", SPACE(depth), expr.op());

    expr.lhs()->visit(*this, depth + 1, false);
    expr.rhs()->visit(*this, depth + 1, true);
}
