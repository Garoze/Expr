#include "Parser/Node.hpp"

Node::Node(AST_kind kind)
    : m_kind(kind)
{}

auto Node::kind() const -> AST_kind
{
    return m_kind;
}
