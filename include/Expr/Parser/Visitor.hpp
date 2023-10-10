#pragma once

#include <string>

class NumberLit;
class BinaryExpr;
class IdentifierExpr;
class AssignExpr;

class Visitor
{
public:
    virtual auto visit(const NumberLit&) -> void = 0;
    virtual auto visit(const BinaryExpr&) -> void = 0;
    virtual auto visit(const IdentifierExpr&) -> void = 0;
    virtual auto visit(const AssignExpr&) -> void = 0;
};
