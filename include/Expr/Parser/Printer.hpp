#pragma once

#include "Parser/Visitor.hpp"

class Printer : public Visitor
{
public:
    auto makePrefix(int, bool = false) -> std::string;

    auto visit(const NumberLit&, std::string, int, bool = true)
        -> void override;

    auto visit(const BinaryExpr&, std::string, int, bool = true)
        -> void override;
};
