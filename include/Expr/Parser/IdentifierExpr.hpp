#pragma once

#include <string>

#include "Parser/Expression.hpp"

class IdentifierExpr : public Expression
{
public:
    IdentifierExpr(std::string);

    auto visit(Visitor&) -> void override;

    [[nodiscard]] auto name() const
    {
        return m_name;
    }

private:
    std::string m_name;
};
