#include "Parser/ProgramExpr.hpp"
#include <vector>

ProgramExpr::ProgramExpr()
    : Expression{ AST_kind::ProgramExpr }
{}

auto ProgramExpr::visit(Visitor& visitor) -> void
{
    visitor.visit(*this);
}
