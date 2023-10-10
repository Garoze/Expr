#include <iostream>
#include <string>

#include "fmt/core.h"

#include "Lexer/Lexer.hpp"
#include "Parser/Parser.hpp"

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

        auto tokens = l.lex_line(input, false);
        input = "";

        Parser p(tokens);
        p.Parse(true);
    }

    return EXIT_SUCCESS;
}
