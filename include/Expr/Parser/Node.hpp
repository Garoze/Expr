#pragma once

#include <string>
#include <unordered_map>

enum class AST_kind
{
    NumberLiteral,
    BinaryExpression,
};

std::unordered_map<AST_kind, std::string> KIND_NAMES = {
    { AST_kind::NumberLiteral, "NumberLiteral" },
    { AST_kind::BinaryExpression, "BinaryExpression" },
};

class Node
{
public:
    Node(AST_kind);

    auto kind() const -> AST_kind;

private:
    AST_kind m_kind;
};
