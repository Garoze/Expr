#include "Parser/Expression.hpp"

Expression::Expression()
    : Node{ Kind::NumberLiteral }
{}

Expression::Expression(Kind kind)
    : Node{ kind }
{}

auto Expression::visit(Visitor&) -> void
{}
