#include "Parser/BinaryExpression.hpp"

BinaryExpr::BinaryExpr(Expression lhs, Expression rhs, std::string op)
    : Expression{ AST_kind::BinaryExpression }
    , m_lhs(lhs)
    , m_rhs(rhs)
    , m_op(op)
{}
