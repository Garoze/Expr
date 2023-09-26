#pragma once

#include "fmt/core.h"

class NumberLiteral;
class BinaryExpression;

class Visitor
{
public:
    virtual auto visit(const NumberLiteral& num) -> void = 0;
    virtual auto visit(const BinaryExpression& exp) -> void = 0;
};

class Printer : public Visitor
{
public:
    auto visit(const NumberLiteral& num) -> void override;
    auto visit(const BinaryExpression& expr) -> void override;
};
