#pragma once

#include <memory>

#include "Parser/Expression.hpp"

class BinaryExpression : public Expression
{
public:
    BinaryExpression(Expr, Expr, std::string);

    auto visit(Visitor&) -> void override;

    [[nodiscard]] auto op() const
    {
        return m_op;
    }

    [[nodiscard]] auto lhs() const
    {
        return m_lhs.get();
    }

    [[nodiscard]] auto rhs() const
    {
        return m_rhs.get();
    }

private:
    Expr m_lhs;
    Expr m_rhs;
    std::string m_op;
};
