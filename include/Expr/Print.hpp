#pragma once

#include <format>
#include <iostream>

namespace expr {

template <typename... T>
inline auto print(std::format_string<T...> fmt, T&&... args) noexcept -> void
{
    std::format_to(std::ostreambuf_iterator<char>(std::cout), fmt,
                   std::forward<T>(args)...);
}

} // namespace expr
