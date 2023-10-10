#pragma once

#include <memory>

#include "Parser/IdentifierExpr.hpp"

class AssignExpr : public Expression
{
public:
    AssignExpr(std::unique_ptr<IdentifierExpr>, std::unique_ptr<Expression>);

    auto visit(Visitor&) -> void override;

    [[nodiscard]] auto identifier() const -> IdentifierExpr*;
    [[nodiscard]] auto expr() const -> Expression*;

private:
    std::unique_ptr<IdentifierExpr> m_identifer;
    std::unique_ptr<Expression> m_expr;
};
