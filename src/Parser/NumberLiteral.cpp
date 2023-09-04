#include <string>

#include "Parser/AST.hpp"
#include "Parser/NumberLiteral.hpp"

NumberLiteral::NumberLiteral(double value)
    : Expression{ AST_kind::Node_NumberLiteral }
    , m_value(value)
{}

auto NumberLiteral::print() const -> std::string
{
    return std::to_string(m_value);
}
