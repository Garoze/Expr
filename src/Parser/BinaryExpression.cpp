#include <algorithm>

#include "Parser/BinaryExpression.hpp"

BinaryExpression::BinaryExpression(std::unique_ptr<Expression> lhs,
                                   std::unique_ptr<Expression> rhs,
                                   std::string op)
    : Expression{ AST_kind::BinaryExpression }
    , m_lhs(std::move(lhs))
    , m_rhs(std::move(rhs))
    , m_op(op)
{}

auto BinaryExpression::lhs() const -> Expression*
{
    return m_lhs.get();
}

auto BinaryExpression::rhs() const -> Expression*
{
    return m_rhs.get();
}

auto BinaryExpression::op() const -> std::string
{
    return m_op;
}

auto BinaryExpression::visit(Visitor& visitor, int depth) -> void
{
    visitor.visit(*this, depth);
}
