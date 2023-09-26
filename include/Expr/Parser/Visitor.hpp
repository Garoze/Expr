#pragma once

#include "fmt/core.h"

class NumberLiteral;
class BinaryExpression;

class Visitor
{
public:
    virtual auto visit(const NumberLiteral& num, int, bool) -> void = 0;
    virtual auto visit(const BinaryExpression& exp, int, bool) -> void = 0;
};

class Printer : public Visitor
{
public:
    auto visit(const NumberLiteral& num, int depth = 0, bool = false)
        -> void override;
    auto visit(const BinaryExpression& expr, int depth = 0, bool = false)
        -> void override;

    auto makePrefix(int, bool = false) -> std::string;
};
