#pragma once

#include "Parser/Expression.hpp"

class BinaryExpression : public Expression
{
public:
    BinaryExpression(Expression, Expression, std::string);

private:
    Expression m_lhs;
    Expression m_rhs;
    std::string m_op;
};
