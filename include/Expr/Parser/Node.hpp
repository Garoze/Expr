#pragma once

#include <string>
#include <unordered_map>

enum class AST_kind
{
    NumberLiteral,
    BinaryExpression,
};

class Node
{
public:
    Node(AST_kind);

    auto kind() const -> AST_kind;

private:
    AST_kind m_kind;
};
