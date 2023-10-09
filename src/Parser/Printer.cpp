#include <string>

#include "fmt/core.h"

#include "Parser/BinaryExpr.hpp"
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
    fmt::print("{}{}Op:{}\n", indent, makePrefix(depth, last), expr.op());

    if (depth > 0)
        indent += last ? "    " : " │  ";

    expr.lhs()->visit(*this, indent, depth + 1, false);
    expr.rhs()->visit(*this, indent, depth + 1, true);
}
