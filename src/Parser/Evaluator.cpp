#include "fmt/core.h"

#include "Parser/AssignExpr.hpp"
#include "Parser/BinaryExpr.hpp"
#include "Parser/Evaluator.hpp"
#include "Parser/IdentifierExpr.hpp"
#include "Parser/NumberLit.hpp"

auto Evaluator::visit(const NumberLit& lit) -> void
{
    m_value = lit.value();
}

auto Evaluator::visit(const IdentifierExpr& identifier) -> void
{
    if (m_symbol_table.contains(identifier.name()))
    {
        m_value = m_symbol_table.at(identifier.name());
    }
    else
    {
        fmt::print("Identifier: `{}` don't exists on the symbol_table!\n",
                   identifier.name());
        m_value = std::numeric_limits<double>::quiet_NaN();
    }
}

auto Evaluator::visit(const AssignExpr& assign) -> void
{
    assign.expr()->visit(*this);

    m_symbol_table[assign.identifier()->name()] = m_value;
}

auto Evaluator::visit(const BinaryExpr& bop) -> void
{
    bop.lhs()->visit(*this);
    auto lhs = m_value;

    bop.rhs()->visit(*this);
    auto rhs = m_value;

    switch (bop.op().at(0))
    {
        case '+':
            m_value = lhs + rhs;
            break;
        case '-':
            m_value = lhs - rhs;
            break;
        case '*':
            m_value = lhs * rhs;
            break;
        case '/':
            m_value = lhs / rhs;
            break;

        default:
            break;
    }
}

auto Evaluator::value() const -> double
{
    return m_value;
}
