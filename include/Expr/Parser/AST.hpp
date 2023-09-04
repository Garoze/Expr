#pragma once

#include <string>
#include <vector>

enum class AST_kind
{
    Node_Error,
    Node_NumberLiteral,
    Node_BinaryOperation,
};

class AST_Node
{
public:
    AST_Node(AST_kind);

    virtual ~AST_Node() = default;

    [[nodiscard]] virtual auto print() const -> std::string = 0;

private:
    AST_kind m_kind;
};
