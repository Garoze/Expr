#pragma once

#include "Parser/Expression.hpp"

class NumberLiteral : public Expression
{
public:
    NumberLiteral(double);

private:
    double m_value;
};
