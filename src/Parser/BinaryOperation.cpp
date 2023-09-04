#include "Parser/BinaryOperation.hpp"
#include "Parser/Expression.hpp"

BinaryOperation::BinaryOperation(std::string op, Expression left,
                                 Expression right)
    : Expression{ AST_kind::Node_BinaryOperation }
    , m_op(op)
    , m_left(left)
    , m_right(right)
{}

auto BinaryOperation::print() const -> std::string
{
    return "";
}
