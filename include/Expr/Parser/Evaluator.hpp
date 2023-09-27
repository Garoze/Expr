#pragma once

#include "Parser/Visitor.hpp"

class NumberLit;
class BinaryExpr;
class Expression;

class Eval
{
public:
    virtual auto eval(const NumberLit&) -> double = 0;
    virtual auto eval(const BinaryExpr&) -> double = 0;
};

class Evaluator : public Eval
{
public:
    auto eval(const NumberLit&) -> double override;
    auto eval(const BinaryExpr&) -> double override;
};
