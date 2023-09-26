#include <algorithm>

#include "Parser/BinaryExpression.hpp"

BinaryExpression::BinaryExpression(std::unique_ptr<Expression> lhs,
                                   std::unique_ptr<Expression> rhs,
                                   std::string op)
    : Expression{ AST_kind::BinaryExpression }
    , m_lhs(std::move(lhs))
    , m_rhs(std::move(rhs))
    , m_op(op)
{}
