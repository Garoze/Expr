#include "Parser/IdentifierExpr.hpp"

IdentifierExpr::IdentifierExpr(std::string name)
    : Expression{ AST_kind::IdentifierExpr }
    , m_name(name)
{}

auto IdentifierExpr::name() const -> std::string
{
    return m_name;
}

auto IdentifierExpr::visit(Visitor& visitor, std::string indent, int depth,
                           bool last) -> void
{
    visitor.visit(*this, indent, depth, last);
}

auto IdentifierExpr::eval(Evaluator& evaluator) -> double
{
    return evaluator.eval(*this);
}
