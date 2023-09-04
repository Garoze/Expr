#include "Parser/AST.hpp"

#include "Parser/Expression.hpp"

Expression::Expression()
    : AST_Node{ AST_kind::Node_NumberLiteral }
{}

Expression::Expression(AST_kind kind)
    : AST_Node{ kind }
    , m_kind(kind)
{}

auto Expression::print() const -> std::string
{
    return "";
}
