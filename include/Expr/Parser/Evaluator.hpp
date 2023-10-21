#pragma once

#include <unordered_map>

#include "Parser/Visitor.hpp"

class NumberLiteral;
class BinaryExpression;
class Expression;
class AssignExpression;

class Evaluator : public Visitor
{
public:
    auto visit(const NumberLiteral&) -> void override;
    auto visit(const BinaryExpression&) -> void override;
    auto visit(const IdentifierExpr&) -> void override;
    auto visit(const AssignExpression&) -> void override;
    auto visit(const ProgramExpr&) -> void override;

    [[nodiscard]] auto value() const -> double;

private:
    double m_value;
    std::unordered_map<std::string, double> m_symbol_table;
};
