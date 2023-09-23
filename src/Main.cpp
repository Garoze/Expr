#include <iostream>
#include <string>

#include "Lexer/Lexer.hpp"
#include "fmt/core.h"

int main()
{
    Lexer l;

    fmt::print("Basic expression evaluator!\n");

    std::string input;
    for (;;)
    {
        fmt::print("> ");
        std::getline(std::cin, input);
        l.lex_line(input);
        input = "";
    }

    return EXIT_SUCCESS;
}
