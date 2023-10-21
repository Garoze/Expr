#include <algorithm>

#include "Parser/AssignExpr.hpp"

AssignExpression::AssignExpression(Expr expr, Identifier identifier)
    : Expression{ Kind::AssignExpression }
    , m_expr(std::move(expr))
    , m_identifier(std::move(identifier))
{}

auto AssignExpression::visit(Visitor& visitor) -> void
{
    visitor.visit(*this);
}
