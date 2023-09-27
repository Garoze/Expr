#pragma once

#include "Parser/Expression.hpp"

class NumberLit : public Expression
{
public:
    NumberLit(double);

    [[nodiscard]] auto value() const -> double;

    auto visit(Visitor&, std::string = "", int = 0, bool = false)
        -> void override;

private:
    double m_value;
};
