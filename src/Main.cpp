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

        if (input == "q" || input == "quit")
            break;

        l.lex_line(input, true);
        input = "";
    }

    return EXIT_SUCCESS;
}
