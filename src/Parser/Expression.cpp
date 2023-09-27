#include "Parser/Expression.hpp"

Expression::Expression()
    : Node{ AST_kind::NumberLiteral }
{}

Expression::Expression(AST_kind kind)
    : Node{ kind }
{}

auto Expression::visit(Visitor&, std::string, int, bool) -> void
{}

auto Expression::eval(Evaluator&) -> double
{
    return 0;
}
