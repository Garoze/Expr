#pragma once

#include "fmt/core.h"

class NumberLiteral;
class BinaryExpression;

class Visitor
{
public:
    virtual auto visit(const NumberLiteral& num, int) -> void = 0;
    virtual auto visit(const BinaryExpression& exp, int) -> void = 0;
};

class Printer : public Visitor
{
public:
    auto visit(const NumberLiteral& num, int depth = 0) -> void override;
    auto visit(const BinaryExpression& expr, int depth = 0) -> void override;
};
