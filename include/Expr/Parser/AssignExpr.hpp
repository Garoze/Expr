#pragma once

#include <memory>

#include "Parser/IdentifierExpr.hpp"

class AssignExpression : public Expression
{
public:
    AssignExpression(Expr, Identifier);

    auto visit(Visitor&) -> void override;

    [[nodiscard]] auto identifier() const
    {
        return m_identifier.get();
    }

    [[nodiscard]] auto expr() const
    {
        return m_expr.get();
    }

private:
    Expr m_expr;
    Identifier m_identifier;
};
