#pragma once

#include "Parser/Expression.hpp"

class BinaryExpr : public Expression
{
public:
    BinaryExpr(Expression, Expression, std::string);

private:
    Expression m_lhs;
    Expression m_rhs;
    std::string m_op;
};
