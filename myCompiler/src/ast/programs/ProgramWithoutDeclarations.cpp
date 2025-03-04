#include "programs/ProgramWithoutDeclarations.hpp"

ProgramWithoutDeclarations::ProgramWithoutDeclarations(std::vector<std::shared_ptr<Command>> commands, const Location& loc)
    : Program(commands, loc) {}