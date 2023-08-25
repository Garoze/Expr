#pragma once

#include "Kind.hpp"
#include "Location.hpp"
#include "Value.hpp"

class Token
{
public:
    Token(kind_t, value_t, std::size_t, std::size_t);

    [[nodiscard]] auto kind() const -> kind_t;
    [[nodiscard]] auto value() const -> Value;
    [[nodiscard]] auto location() const -> Location;

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
