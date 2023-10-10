#include "Parser/AssingExpr.hpp"
#include <algorithm>

AssignExpr::AssignExpr(std::unique_ptr<IdentifierExpr> identifier,
                       std::unique_ptr<Expression> expr)
    : Expression{ AST_kind::AssignExpr }
    , m_identifier(std::move(identifier))
    , m_expr(std::move(expr))
{}

auto AssignExpr::identifier() const -> std::string
{
    return m_identifier->name();
}

auto AssignExpr::expr() const -> Expression*
{
    return m_expr.get();
}

auto AssignExpr::visit(Visitor& visitor, std::string indent, int depth,
                       bool last) -> void
{
    visitor.visit(*this, indent, depth, last);
}

auto AssignExpr::eval(Evaluator& evaluator) -> double
{
    return evaluator.eval(*this);
}
