#include <string>

#include "fmt/core.h"

#include "Parser/BinaryExpression.hpp"
#include "Parser/NumberLiteral.hpp"
#include "Parser/Printer.hpp"
#include "Parser/Visitor.hpp"

auto Printer::makePrefix(int depth, bool last) -> std::string
{
    if (depth == 0)
    {
        return "";
    }

    return (last ? "└──" : "├──");
}

auto Printer::visit(const NumberLiteral& num, std::string indent, int depth,
                    bool last) -> void
{
    fmt::print("{}{}Lit: {}\n", indent, makePrefix(depth, last), num.value());
}

auto Printer::visit(const BinaryExpression& expr, std::string indent, int depth,
                    bool last) -> void
{
    fmt::print("{}{}Op:{}\n", indent, makePrefix(depth, last), expr.op());

    if (depth > 0)
        indent += last ? "    " : "│   ";

    expr.lhs()->visit(*this, indent, depth + 1, false);
    expr.rhs()->visit(*this, indent, depth + 1, true);
}
