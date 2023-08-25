#pragma once

#include <string>
#include <variant>

// TokenValue
using value_t = std::variant<std::monostate, int, std::string>;

class Value
{
public:
    Value(value_t);

    [[nodiscard]] auto value() const -> value_t;
    [[nodiscard]] auto as_string() const -> std::string;

public:
    constexpr explicit operator bool() noexcept
    {
        return !m_value.valueless_by_exception();
    }

private:
    value_t m_value;
};
