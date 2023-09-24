#include "Parser/Expression.hpp"

Expression::Expression()
    : Node{ AST_kind::NumberLiteral }
{}

Expression::Expression(AST_kind kind)
    : Node{ kind }
{}
