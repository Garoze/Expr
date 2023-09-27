#include <algorithm>

#include "Parser/BinaryExpr.hpp"

BinaryExpr::BinaryExpr(std::unique_ptr<Expression> lhs,
                       std::unique_ptr<Expression> rhs, std::string op)
    : Expression{ AST_kind::BinaryExpression }
    , m_lhs(std::move(lhs))
    , m_rhs(std::move(rhs))
    , m_op(op)
{}

auto BinaryExpr::lhs() const -> Expression*
{
    return m_lhs.get();
}

auto BinaryExpr::rhs() const -> Expression*
{
    return m_rhs.get();
}

auto BinaryExpr::op() const -> std::string
{
    return m_op;
}

auto BinaryExpr::visit(Visitor& visitor, std::string indent, int depth,
                       bool last) -> void
{
    visitor.visit(*this, indent, depth, last);
}

auto BinaryExpr::eval(Evaluator& evaluator) -> double
{
    return evaluator.eval(*this);
}
