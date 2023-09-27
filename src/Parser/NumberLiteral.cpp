#include "Parser/NumberLiteral.hpp"

NumberLiteral::NumberLiteral(double value)
    : Expression{ AST_kind::NumberLiteral }
    , m_value(value)
{}

auto NumberLiteral::value() const -> double
{
    return m_value;
}

auto NumberLiteral::visit(Visitor& visitor, std::string indent, int depth,
                          bool last) -> void
{
    visitor.visit(*this, indent, depth, last);
}
