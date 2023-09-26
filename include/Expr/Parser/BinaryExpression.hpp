#pragma once

#include <memory>

#include "Parser/Expression.hpp"

class BinaryExpression : public Expression
{
public:
    BinaryExpression(std::unique_ptr<Expression>, std::unique_ptr<Expression>,
                     std::string);

private:
    std::unique_ptr<Expression> m_lhs;
    std::unique_ptr<Expression> m_rhs;
    std::string m_op;
};
