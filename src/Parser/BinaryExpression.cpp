#include "Parser/BinaryExpr.hpp"

BinaryExpression::BinaryExpression(Expr lhs, Expr rhs, std::string op)
    : Expression{ Kind::BinaryExpression }
    , m_lhs(std::move(lhs))
    , m_rhs(std::move(rhs))
    , m_op(op)
{}

auto BinaryExpression::visit(Visitor& visitor) -> void
{
    visitor.visit(*this);
}
