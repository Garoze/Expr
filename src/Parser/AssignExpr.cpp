#include <algorithm>

#include "Parser/AssignExpr.hpp"

AssignExpr::AssignExpr(std::unique_ptr<IdentifierExpr> identifier,
                       std::unique_ptr<Expression> expr)
    : Expression{ AST_kind::AssignExpr }
    , m_identifer(std::move(identifier))
    , m_expr(std::move(expr))
{}

auto AssignExpr::identifier() const -> IdentifierExpr*
{
    return m_identifer.get();
}

auto AssignExpr::expr() const -> Expression*
{
    return m_expr.get();
}

auto AssignExpr::visit(Visitor& visitor) -> void
{
    visitor.visit(*this);
}
