#include "fmt/core.h"

#include "Parser/BinaryExpression.hpp"
#include "Parser/NumberLiteral.hpp"
#include "Parser/Visitor.hpp"

auto Printer::visit(const NumberLiteral& num) -> void
{
    fmt::print("Lit: {}\n", num.value());
}

auto Printer::visit(const BinaryExpression& expr) -> void
{
    fmt::print("Op: {}\n", expr.op());
    expr.lhs()->visit(*this);
    expr.rhs()->visit(*this);
}
