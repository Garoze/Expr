#pragma once

#include "Parser/Expression.hpp"
#include <string>

class IdentifierExpr : public Expression
{
public:
    IdentifierExpr(std::string);

    [[nodiscard]] auto name() const -> std::string;

    auto visit(Visitor&, std::string = "", int = 0, bool = false)
        -> void override;

    auto eval(Evaluator&) -> double override;

private:
    std::string m_name;
};
