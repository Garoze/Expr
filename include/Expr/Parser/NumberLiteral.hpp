#pragma once

#include "Parser/Expression.hpp"

class NumberLiteral : public Expression
{
public:
    NumberLiteral(double);

    [[nodiscard]] auto value() const -> double;

    auto visit(Visitor&, int = 0) -> void override;

private:
    double m_value;
};
