#pragma once

#include "Parser/Node.hpp"
#include "Parser/Visitor.hpp"

class Expression : public Node
{
public:
    Expression();
    Expression(AST_kind);

    auto visit(Visitor&, int = 0) -> void override;
};
