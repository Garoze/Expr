#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

enum class kind_t : std::uint8_t
{
    __EOF = 0,
    __LAST_VALID_CHAR = 127, // Reserve first 128 values for one-char tokens
    TOKEN_NUMBER,
    TOKEN_ERROR,
};

class Kind
{
public:
    Kind(char);
    Kind(kind_t);

    [[nodiscard]] auto raw() const -> kind_t;

    [[nodiscard]] auto as_int() const -> int;
    [[nodiscard]] auto as_int(kind_t) const -> int;
    [[nodiscard]] auto as_string() const -> std::string;

private:
    kind_t m_kind;
};
