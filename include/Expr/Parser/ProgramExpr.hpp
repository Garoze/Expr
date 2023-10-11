#pragma once

#include <memory>
#include <span>
#include <vector>

#include "Parser/Expression.hpp"

class ProgramExpr : public Expression
{
public:
    ProgramExpr();

    auto visit(Visitor&) -> void override;

    std::vector<std::unique_ptr<Expression>> body;
};
