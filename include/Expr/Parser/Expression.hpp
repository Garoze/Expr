#pragma once

#include "Parser/Node.hpp"

class Expression : public Node
{
public:
    Expression();
    Expression(AST_kind);
};
