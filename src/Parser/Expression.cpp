#include "Parser/Expression.hpp"

Expression::Expression()
    : Node{ AST_kind::NumberLit }
{}

Expression::Expression(AST_kind kind)
    : Node{ kind }
{}

auto Expression::visit(Visitor&) -> void
{}
