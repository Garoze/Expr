#include "Parser/Node.hpp"

std::unordered_map<AST_kind, std::string> KIND_NAMES = {
    { AST_kind::NumberLiteral, "NumberLiteral" },
    { AST_kind::BinaryExpression, "BinaryExpression" },
};

Node::Node(AST_kind kind)
    : m_kind(kind)
{}

auto Node::kind() const -> AST_kind
{
    return m_kind;
}