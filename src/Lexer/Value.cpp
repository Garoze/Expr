#include <iostream>
#include <string>
#include <variant>

#include "Lexer/Value.hpp"

Value::Value(value_t value)
    : m_value(value)
{}

auto Value::raw() const -> value_t
{
    return m_value;
}

auto Value::as_string() const -> std::string
{
    auto visitor = [&](auto& arg) -> std::string {
        using T = std::decay_t<decltype(arg)>;

        if constexpr (std::is_same_v<T, std::monostate>)
        {
            return "";
        }
        else if constexpr (std::is_same_v<T, double>)
        {
            return std::to_string(arg);
        }
        else if constexpr (std::is_same_v<T, std::string>)
        {
            return arg;
        }
    };

    return std::visit(visitor, m_value);
}
