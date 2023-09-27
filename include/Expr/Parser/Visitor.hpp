#pragma once

#include "fmt/core.h"

class NumberLiteral;
class BinaryExpression;

class Visitor
{
public:
    virtual auto visit(const NumberLiteral& num, std::string, int, bool)
        -> void = 0;
    virtual auto visit(const BinaryExpression& exp, std::string, int, bool)
        -> void = 0;
};

class Printer : public Visitor
{
public:
    auto visit(const NumberLiteral& num, std::string, int, bool = true)
        -> void override;
    auto visit(const BinaryExpression& expr, std::string, int, bool = true)
        -> void override;

    auto makePrefix(int, bool = false) -> std::string;
};
