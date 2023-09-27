#pragma once

#include <memory>

#include "Parser/Expression.hpp"

class BinaryExpression : public Expression
{
public:
    BinaryExpression(std::unique_ptr<Expression>, std::unique_ptr<Expression>,
                     std::string);

    auto lhs() const -> Expression*;
    auto rhs() const -> Expression*;
    auto op() const -> std::string;

    auto visit(Visitor&, std::string, int = 0, bool = false) -> void override;

private:
    std::unique_ptr<Expression> m_lhs;
    std::unique_ptr<Expression> m_rhs;
    std::string m_op;
};
