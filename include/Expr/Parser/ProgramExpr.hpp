#pragma once

#include <span>
#include <vector>

#include "Parser/Expression.hpp"

class ProgramExpr : public Expression
{
public:
    ProgramExpr();

    auto visit(Visitor&) -> void override;

    std::vector<Expr> body;
};
