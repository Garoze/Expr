#include "Parser/Node.hpp"

Node::Node(Kind kind)
    : m_kind(kind)
{}

auto Node::kind() const -> Kind
{
    return m_kind;
}
