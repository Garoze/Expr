#include "Parser/NumberLiteral.hpp"

NumberLiteral::NumberLiteral(double value)
    : Expression{ AST_kind::NumberLiteral }
    , m_value(value)
{}
