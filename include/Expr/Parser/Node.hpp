#pragma once

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "Parser/Visitor.hpp"

enum class AST_kind
{
    NumberLit,
    BinaryExpr,
    IdentifierExpr,
    AssignExpr,
};

class Node
{
public:
    Node(AST_kind);
    virtual ~Node() = default;

    virtual auto visit(Visitor&) -> void = 0;

    [[nodiscard]] auto kind() const -> AST_kind;

private:
    AST_kind m_kind;
};
