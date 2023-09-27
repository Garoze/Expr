#include "Parser/NumberLit.hpp"

NumberLit::NumberLit(double value)
    : Expression{ AST_kind::NumberLiteral }
    , m_value(value)
{}

auto NumberLit::value() const -> double
{
    return m_value;
}

auto NumberLit::visit(Visitor& visitor, std::string indent, int depth,
                      bool last) -> void
{
    visitor.visit(*this, indent, depth, last);
}
