#include <string>

#include "fmt/core.h"

#include "Parser/BinaryExpression.hpp"
#include "Parser/NumberLiteral.hpp"
#include "Parser/Visitor.hpp"

#define SPACE(n) fmt::format("{:>{}}", "", (n) + 1)

auto Printer::makePrefix(int depth, bool last) -> std::string
{
    if (depth == 0)
    {
        return "";
    }
    else
    {
        return (last ? "└──" : "├──");
    }
}

auto Printer::visit(const NumberLiteral& num, std::string indent, int depth,
                    bool last) -> void
{
    auto prefix = makePrefix(depth, last);
    fmt::print("{}{}Lit: {}\n", indent, prefix, num.value());
}

auto Printer::visit(const BinaryExpression& expr, std::string indent, int depth,
                    bool last) -> void
{
    auto prefix = makePrefix(depth, last);
    fmt::print("{}{}Op:{}\n", indent, prefix, expr.op());

    indent += last ? "    " : "│   ";

    expr.lhs()->visit(*this, indent, depth + 1, false);
    expr.rhs()->visit(*this, indent, depth + 1, true);
}
