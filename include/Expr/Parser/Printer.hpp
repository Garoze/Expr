#pragma once

#include "Parser/Visitor.hpp"

class Printer : public Visitor
{
public:
    auto visit(const NumberLiteral& num, std::string, int, bool = true)
        -> void override;
    auto visit(const BinaryExpression& expr, std::string, int, bool = true)
        -> void override;

    auto makePrefix(int, bool = false) -> std::string;
};
