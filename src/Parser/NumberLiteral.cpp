#include "Parser/NumberLiteral.hpp"

NumberLiteral::NumberLiteral(double value)
    : Expression{ AST_kind::NumberLiteral }
    , m_value(value)
{}

auto NumberLiteral::value() const -> double
{
    return m_value;
}

auto NumberLiteral::visit(Visitor& visitor, int depth) -> void
{
    visitor.visit(*this, depth);
}
