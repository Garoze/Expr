#pragma once

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "Parser/Visitor.hpp"

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

    virtual auto visit(Visitor&, std::string, int = 0, bool = true) -> void = 0;
    virtual ~Node() = default;

private:
    AST_kind m_kind;
};
