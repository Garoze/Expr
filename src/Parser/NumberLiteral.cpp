#include "Parser/NumberLit.hpp"

NumberLit::NumberLit(double value)
    : Expression{ AST_kind::NumberLit }
    , m_value(value)
{}

auto NumberLit::value() const -> double
{
    return m_value;
}

auto NumberLit::visit(Visitor& visitor) -> void
{
    visitor.visit(*this);
}
