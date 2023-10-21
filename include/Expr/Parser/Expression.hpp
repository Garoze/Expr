#pragma once

#include "Parser/Node.hpp"
#include "Parser/Visitor.hpp"

#include <memory>

class Expression : public Node
{
public:
    Expression();
    Expression(Kind);

    auto visit(Visitor&) -> void override;
};
