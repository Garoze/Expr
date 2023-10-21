#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "Parser/Visitor.hpp"

class Expression;
using Expr = std::unique_ptr<Expression>;

class IdentifierExpr;
using Identifier = std::unique_ptr<IdentifierExpr>;

class Node
{
public:
    enum class Kind
    {
        NumberLiteral,
        BinaryExpression,
        AssignExpression,
        ProgramExpression,
        Identifier,
    };

    Node(Kind);
    virtual ~Node() = default;

    virtual auto visit(Visitor&) -> void = 0;

    [[nodiscard]] auto kind() const -> Kind;

private:
    Kind m_kind;
};
