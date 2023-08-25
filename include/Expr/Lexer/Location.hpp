#pragma once

#include <cstddef>
#include <string_view>

class Location
{
public:
    Location(std::size_t, std::size_t);

    [[nodiscard]] auto line() const -> std::size_t;
    [[nodiscard]] auto column() const -> std::size_t;
    [[nodiscard]] auto as_string() const -> std::string;

private:
    std::size_t m_line;
    std::size_t m_column;
};
