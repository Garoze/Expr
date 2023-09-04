#pragma once

#include <string>

#include "AST.hpp"

class Expression : public AST_Node
{
public:
    Expression();
    Expression(AST_kind);

    [[nodiscard]] virtual auto print() const -> std::string override;

private:
    AST_kind m_kind;
};
