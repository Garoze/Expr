#pragma once

#include <memory>

#include "Parser/Expression.hpp"

class BinaryExpr : public Expression
{
public:
    BinaryExpr(std::unique_ptr<Expression>, std::unique_ptr<Expression>,
               std::string);

    auto visit(Visitor&) -> void override;

    [[nodiscard]] auto op() const -> std::string;
    [[nodiscard]] auto lhs() const -> Expression*;
    [[nodiscard]] auto rhs() const -> Expression*;

private:
    std::string m_op;
    std::unique_ptr<Expression> m_lhs;
    std::unique_ptr<Expression> m_rhs;
};
