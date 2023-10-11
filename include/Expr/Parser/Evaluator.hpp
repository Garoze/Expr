#pragma once

#include <unordered_map>

#include "Parser/Visitor.hpp"

class NumberLit;
class BinaryExpr;
class Expression;

class Evaluator : public Visitor
{
public:
    auto visit(const NumberLit&) -> void override;
    auto visit(const BinaryExpr&) -> void override;
    auto visit(const IdentifierExpr&) -> void override;
    auto visit(const AssignExpr&) -> void override;
    auto visit(const ProgramExpr&) -> void override;

    [[nodiscard]] auto value() const -> double;

private:
    double m_value;
    std::unordered_map<std::string, double> m_symbol_table;
};
