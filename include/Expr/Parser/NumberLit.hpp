#pragma once

#include "Parser/Expression.hpp"

class NumberLit : public Expression
{
public:
    NumberLit(double);

    auto visit(Visitor&) -> void override;

    [[nodiscard]] auto value() const -> double;

private:
    double m_value;
};
