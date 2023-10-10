#include <format>
#include <string>

#include "fmt/core.h"

#include "Parser/AssignExpr.hpp"
#include "Parser/BinaryExpr.hpp"
#include "Parser/IdentifierExpr.hpp"
#include "Parser/NumberLit.hpp"
#include "Parser/Printer.hpp"

auto prefix(int depth, bool last) -> std::string
{
    if (depth == 0)
    {
        return "";
    }

    return (last ? " └──" : " ├──");
}

auto indent(std::string indent, int depth, bool last) -> std::string
{
    return fmt::format("{}{}", indent, prefix(depth, last));
}

auto Printer::visit(const NumberLit& num) -> void
{
    fmt::print("{}Lit: {}\n", indent(m_indent, m_depth, m_last), num.value());
}

auto Printer::visit(const BinaryExpr& expr) -> void
{
    auto save_indent = m_indent;

    fmt::print("{}Op: {}\n", indent(m_indent, m_depth, m_last), expr.op());

    if (m_depth > 0)
        m_indent += (m_last ? "    " : " │  ");

    m_depth++;

    m_last = false;
    expr.lhs()->visit(*this);

    m_last = true;
    expr.rhs()->visit(*this);

    m_indent = save_indent;
}

auto Printer::visit(const IdentifierExpr& id) -> void
{
    fmt::print("{}Id: {}\n", indent(m_indent, m_depth, m_last), id.name());
}

auto Printer::visit(const AssignExpr& assign) -> void
{
    auto save_indent = m_indent;

    fmt::print("{}Var: {}\n", indent(m_indent, m_depth, m_last),
               assign.identifier()->name());

    if (m_depth > 0)
        m_indent += (m_last ? "    " : " │  ");

    m_depth++;

    m_last = true;
    assign.expr()->visit(*this);

    m_indent = save_indent;
}
