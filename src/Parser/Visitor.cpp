#include "fmt/core.h"

#include "Parser/BinaryExpression.hpp"
#include "Parser/NumberLiteral.hpp"
#include "Parser/Visitor.hpp"

auto Printer::visit(const NumberLiteral& num) -> void
{
    fmt::print("{}", num.value());
}

auto Printer::visit(const BinaryExpression& expr) -> void
{
    expr.lhs()->visit(*this);
    fmt::print("{}", expr.op());
    expr.rhs()->visit(*this);
}
