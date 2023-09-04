#include "AST.hpp"
#include "Expression.hpp"

class NumberLiteral : public Expression
{
public:
    NumberLiteral(double);

    [[nodiscard]] virtual auto print() const -> std::string override;

private:
    double m_value;
};
