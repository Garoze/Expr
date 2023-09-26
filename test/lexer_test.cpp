#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <vector>

// #include "../include/Expr/Lexer/Lexer.hpp"
#include "Lexer/Kind.hpp"
#include "Lexer/Lexer.hpp"
#include "Lexer/Token.hpp"

namespace test {

auto expect_token(std::vector<Token>& tokens, std::size_t index, kind_t kind)
    -> bool
{
    return tokens.at(index).kind().raw() == kind;
}

} // namespace test

TEST(LexerTest, ItShouldReturnTokens)
{
    Lexer l;

    std::string input = "1+2";

    auto tokens = l.lex_line(input);

    ASSERT_GT(tokens.size(), 0);
}

TEST(LexerTest, ItShouldReturn4Tokens)
{
    Lexer l;

    std::string input = "1+2";

    auto tokens = l.lex_line(input);

    ASSERT_GE(tokens.size(), 4);
}

TEST(LexerTest, ItShouldReturnRightTokens)
{
    Lexer l;

    std::string input = "1+2";

    auto tokens = l.lex_line(input);

    ASSERT_EQ(test::expect_token(tokens, 0, kind_t::NUMBERLIT), true);
    ASSERT_EQ(test::expect_token(tokens, 1, kind_t::PLUS), true);
    ASSERT_EQ(test::expect_token(tokens, 2, kind_t::NUMBERLIT), true);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
