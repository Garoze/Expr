#include "Parser/BinaryExpression.hpp"

BinaryExpression::BinaryExpression(Expression lhs, Expression rhs,
                                   std::string op)
    : Expression{ AST_kind::BinaryExpression }
    , m_lhs(lhs)
    , m_rhs(rhs)
    , m_op(op)
{}
