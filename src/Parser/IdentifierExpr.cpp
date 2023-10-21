#include "Parser/IdentifierExpr.hpp"

IdentifierExpr::IdentifierExpr(std::string name)
    : Expression{ Kind::Identifier }
    , m_name(name)
{}

auto IdentifierExpr::visit(Visitor& visitor) -> void
{
    visitor.visit(*this);
}
