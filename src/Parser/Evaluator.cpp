#include "Parser/Evaluator.hpp"
#include "Parser/BinaryExpr.hpp"
#include "Parser/NumberLit.hpp"

auto Evaluator::eval(Expression* expr) -> double
{
    auto lit = static_cast<NumberLit*>(expr);

    return lit->value();
}

auto Evaluator::eval(const NumberLit& lit) -> double
{
    return lit.value();
}

auto Evaluator::eval(const BinaryExpr& bop) -> double
{
    auto lhs = eval(bop.lhs());
    auto rhs = eval(bop.lhs());

    if (bop.op() == "+")
    {
        return lhs + rhs;
    }
    else if (bop.op() == "-")
    {
        return lhs - rhs;
    }
    else if (bop.op() == "*")
    {
        return lhs * rhs;
    }
    if (bop.op() == "/")
    {
        return lhs / rhs;
    }

    return 0;
}
