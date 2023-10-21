#include "Parser/NumberLit.hpp"

NumberLiteral::NumberLiteral(double value)
    : Expression{ Kind::NumberLiteral }
    , m_value(value)
{}

auto NumberLiteral::visit(Visitor& visitor) -> void
{
    visitor.visit(*this);
}
