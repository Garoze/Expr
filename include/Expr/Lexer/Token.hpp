#pragma once

#include <string>

#include "Kind.hpp"
#include "Location.hpp"
#include "Value.hpp"

class Token
{
public:
    Token(char, value_t, std::size_t, std::size_t);
    Token(kind_t, value_t, std::size_t, std::size_t);

    [[nodiscard]] auto kind() const -> const Kind&;
    [[nodiscard]] auto raw_kind() const -> kind_t;
    [[nodiscard]] auto value() const -> Value;
    [[nodiscard]] auto location() const -> Location;

    [[nodiscard]] auto as_string() const -> std::string;

    auto debug(bool = false) const -> void;

public:
    constexpr explicit operator bool() noexcept
    {
        return static_cast<bool>(m_value);
    }

private:
    Kind m_kind;
    Value m_value;
    Location m_location;
};
