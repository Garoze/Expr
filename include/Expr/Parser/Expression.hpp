#pragma once

#include "Parser/Node.hpp"
#include "Parser/Visitor.hpp"

class Expression : public Node
{
public:
    Expression();
    Expression(AST_kind);

    auto visit(Visitor&, std::string = "", int = 0, bool = false)
        -> void override;

    auto eval(Evaluator&) -> double override;
};
