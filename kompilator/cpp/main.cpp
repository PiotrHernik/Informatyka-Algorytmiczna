#include <cstring>
#include <fstream>
#include <iostream>

#include "scanner.hpp"
#include "parser.hpp"


int main(int argc, char const *argv[])
{
    if (argc < 2 || argc > 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> [-d]" << std::endl;
        return 1;
    }

    const char* input_file = argv[1];
    bool debug_flag = (argc == 3) && (std::strcmp(argv[2], "-d") == 0);

    // Otwórz plik wejściowy
    std::ifstream file(input_file);
    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open file " << input_file << std::endl;
        return 1;
    }

    // Ustaw skaner na plik wejściowy
    yy::Scanner scanner{file, std::cout};
    scanner.set_debug(debug_flag);

    yy::Parser parser{scanner};
    parser.set_debug_level(debug_flag);

    return parser();
}