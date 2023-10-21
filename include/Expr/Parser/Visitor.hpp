#pragma once

#include <string>

class NumberLiteral;
class BinaryExpression;
class IdentifierExpr;
class AssignExpression;
class ProgramExpr;

class Visitor
{
public:
    virtual auto visit(const NumberLiteral&) -> void = 0;
    virtual auto visit(const BinaryExpression&) -> void = 0;
    virtual auto visit(const IdentifierExpr&) -> void = 0;
    virtual auto visit(const AssignExpression&) -> void = 0;
    virtual auto visit(const ProgramExpr&) -> void = 0;
};
