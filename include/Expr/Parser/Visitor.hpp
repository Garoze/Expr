#pragma once

#include "fmt/core.h"

class NumberLit;
class BinaryExpr;

class Visitor
{
public:
    virtual auto visit(const NumberLit&, std::string, int, bool) -> void = 0;
    virtual auto visit(const BinaryExpr&, std::string, int, bool) -> void = 0;
};
