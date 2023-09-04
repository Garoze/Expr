#pragma once

#include <string>

#include "Parser/Expression.hpp"
#include "Parser/NumberLiteral.hpp"

class BinaryOperation : Expression
{
public:
    BinaryOperation(std::string, Expression, Expression);

    [[nodiscard]] virtual auto print() const -> std::string override;


private:
    std::string m_op;
    Expression m_left;
    Expression m_right;
};
