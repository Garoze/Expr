#include <algorithm>

#include "Parser/BinaryExpr.hpp"

BinaryExpr::BinaryExpr(std::unique_ptr<Expression> lhs,
                       std::unique_ptr<Expression> rhs, std::string op)
    : Expression{ AST_kind::BinaryExpr }
    , m_op(op)
    , m_lhs(std::move(lhs))
    , m_rhs(std::move(rhs))
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

auto BinaryExpr::visit(Visitor& visitor) -> void
{
    visitor.visit(*this);
}
