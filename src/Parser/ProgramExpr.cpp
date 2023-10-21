#include "Parser/ProgramExpr.hpp"
#include <vector>

ProgramExpr::ProgramExpr()
    : Expression{ Kind::ProgramExpression }
{}

auto ProgramExpr::visit(Visitor& visitor) -> void
{
    visitor.visit(*this);
}
