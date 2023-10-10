#include <format>
#include <string>

#include "fmt/core.h"

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
    auto debug = fmt::format("{}{}", indent, prefix(depth, last));
    // fmt::print("Debug: `{}` {} {}\t", debug, depth, last);

    return debug;
}

auto Printer::visit(const NumberLit& num) -> void
{
    fmt::print("{}Lit: {}\n", indent(m_indent, m_depth, m_last), num.value());
}

auto Printer::visit(const BinaryExpr& expr) -> void
{
    fmt::print("{}Op: {}\n", indent(m_indent, m_depth, m_last), expr.op());

    if (m_depth > 0)
        m_indent += (m_last ? "    " : " │  ");

    m_depth++;

    m_last = false;
    expr.lhs()->visit(*this);

    m_last = true;
    expr.rhs()->visit(*this);
}

auto Printer::visit(const IdentifierExpr& id) -> void
{
    fmt::print("{}Id: {}\n", indent(m_indent, m_depth, m_last), id.name());
}
