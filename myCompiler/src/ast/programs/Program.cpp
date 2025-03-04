#include "Program.hpp"

Program::Program(std::vector<std::shared_ptr<Command>> commands, const Location& loc)
    : commands_(commands), name_("Main"), symbolTable_(SymbolTable(name_)), location_(loc) {}