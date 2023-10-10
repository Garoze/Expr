#include "Parser/Node.hpp"

std::unordered_map<AST_kind, std::string> KIND_NAMES = {
    { AST_kind::NumberLit, "NumberLiteral" },
    { AST_kind::BinaryExpr, "BinaryExpression" },
    { AST_kind::IdentifierExpr, "IdentifierExpression" },
    { AST_kind::AssignExpr, "AssignmentExpression" },
};

Node::Node(AST_kind kind)
    : m_kind(kind)
{}

auto Node::kind() const -> AST_kind
{
    return m_kind;
}
