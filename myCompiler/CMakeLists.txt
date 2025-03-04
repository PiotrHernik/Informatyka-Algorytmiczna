cmake_minimum_required(VERSION 3.10)
project(myCompiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Znalezienie Flex i Bison
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# Generowanie parsera (Bison)
bison_target(Parser src/main/parser.ypp ${CMAKE_BINARY_DIR}/parser.cpp)

# Generowanie skanera (Flex)
# Specify the output header file for Flex using DEFINES_FILE
flex_target(Scanner src/main/scanner.lpp ${CMAKE_BINARY_DIR}/scanner.cpp)


# Połączenie obu generatorów
add_flex_bison_dependency(Scanner Parser)

# Dodanie wszystkich źródeł
file(GLOB_RECURSE SOURCES
    "src/ast/*.cpp"
    "src/ast/**/*.cpp"
    "src/astUtilities/*.cpp"
    "src/errors/*.cpp"
    "src/functions/*.cpp"
    "src/main/*.cpp"
    "src/SymbolTable/*.cpp"
)

# Dodanie wszystkich plików nagłówkowych
include_directories(
    "src/ast"
    "src/ast/argDeclaration"
    "src/ast/args"
    "src/ast/commands"
    "src/ast/conditions"
    "src/ast/declarations"
    "src/ast/expressions"
    "src/ast/identifiers"
    "src/ast/procCall"
    "src/ast/procedures"
    "src/ast/procHead"
    "src/ast/programs"
    "src/ast/values"
    "src/astUtilities"
    "src/errors"
    "src/functions"
    "src/main"
    "src/SymbolTable"
    ${CMAKE_BINARY_DIR}  # Include the directory where scanner.hpp is generated
)

# Tworzenie pliku wykonywalnego
set(GENERATED_SOURCES ${BISON_Parser_OUTPUTS} ${FLEX_Scanner_OUTPUTS})
add_executable(myCompiler ${SOURCES} ${GENERATED_SOURCES})