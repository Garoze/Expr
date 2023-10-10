#pragma once

#include "Parser/Visitor.hpp"

class Printer : public Visitor
{
public:
    auto visit(const NumberLit&) -> void override;
    auto visit(const BinaryExpr&) -> void override;
    auto visit(const IdentifierExpr&) -> void override;
    auto visit(const AssignExpr&) -> void override;

private:
    int m_depth = 0;
    bool m_last = false;
    std::string m_indent = "";
};
