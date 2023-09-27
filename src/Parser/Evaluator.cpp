#include "Parser/Evaluator.hpp"
#include "Parser/BinaryExpr.hpp"
#include "Parser/NumberLit.hpp"

auto Evaluator::eval(const NumberLit& lit) -> double
{
    return lit.value();
}

auto Evaluator::eval(const BinaryExpr& bop) -> double
{
    auto lhs = bop.lhs()->eval(*this);
    auto rhs = bop.rhs()->eval(*this);

    if (bop.op() == "+")
        return lhs + rhs;
    if (bop.op() == "-")
        return lhs - rhs;
    if (bop.op() == "*")
        return lhs * rhs;
    if (bop.op() == "/")
        return lhs / rhs;

    return 0;
}
