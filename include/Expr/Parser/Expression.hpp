#pragma once

#include "Parser/Node.hpp"

class Expression : public Node
{
public:
    Expression();
    Expression(AST_kind);

    // virtual void visit(Visitor& visitor) = 0;
};
