#pragma once

#include "Parser/Expression.hpp"
#include "Parser/IdentifierExpr.hpp"
#include <memory>
#include <string>

class AssignExpr : public Expression
{
public:
    AssignExpr(std::unique_ptr<IdentifierExpr>, std::unique_ptr<Expression>);

    [[nodiscard]] auto identifier() const -> std::string;
    [[nodiscard]] auto expr() const -> Expression*;

    auto visit(Visitor&, std::string = "", int = 0, bool = false)
        -> void override;

    auto eval(Evaluator&) -> double override;

private:
    std::unique_ptr<IdentifierExpr> m_identifier;
    std::unique_ptr<Expression> m_expr;
};
