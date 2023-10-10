#include <string>

#include "fmt/core.h"

#include "Parser/AssingExpr.hpp"
#include "Parser/BinaryExpr.hpp"
#include "Parser/IdentifierExpr.hpp"
#include "Parser/NumberLit.hpp"
#include "Parser/Printer.hpp"

auto Printer::makePrefix(int depth, bool last) -> std::string
{
    if (depth == 0)
    {
        return "";
    }

    return (last ? " └──" : " ├──");
}

auto Printer::visit(const NumberLit& num, std::string indent, int depth,
                    bool last) -> void
{
    fmt::print("{}{}Lit: {}\n", indent, makePrefix(depth, last), num.value());
}

auto Printer::visit(const BinaryExpr& expr, std::string indent, int depth,
                    bool last) -> void
{
    fmt::print("{}{}Op: {}\n", indent, makePrefix(depth, last), expr.op());

    if (depth > 0)
        indent += last ? "    " : " │  ";

    expr.lhs()->visit(*this, indent, depth + 1, false);
    expr.rhs()->visit(*this, indent, depth + 1, true);
}

auto Printer::visit(const IdentifierExpr& identifier, std::string indent,
                    int depth, bool last) -> void
{
    fmt::print("{}{}Id: {}\n", indent, makePrefix(depth, last),
               identifier.name());
}

auto Printer::visit(const AssignExpr& assign, std::string indent, int depth,
                    bool last) -> void
{
    fmt::print("{}{}Var: {}\n", indent, makePrefix(depth, last),
               assign.identifier());

    if (depth > 0)
        indent += last ? "    " : " │  ";

    assign.expr()->visit(*this, indent, depth + 1, true);
}
