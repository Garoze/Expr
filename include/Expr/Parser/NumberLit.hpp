#pragma once

#include "Parser/Expression.hpp"

class NumberLiteral : public Expression
{
public:
    NumberLiteral(double);

    auto visit(Visitor&) -> void override;

    [[nodiscard]] auto value() const
    {
        return m_value;
    }

private:
    double m_value;
};
