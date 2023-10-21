#pragma once

#include "Parser/Visitor.hpp"

class Printer : public Visitor
{
public:
    auto visit(const NumberLiteral&) -> void override;
    auto visit(const BinaryExpression&) -> void override;
    auto visit(const IdentifierExpr&) -> void override;
    auto visit(const AssignExpression&) -> void override;
    auto visit(const ProgramExpr&) -> void override;

private:
    int m_depth = 0;
    bool m_last = false;
    std::string m_indent = "";
};
