#include "programs/ProgramWithDeclarations.hpp"

ProgramWithDeclarations::ProgramWithDeclarations(std::vector<std::shared_ptr<Declaration>> declarations, std::vector<std::shared_ptr<Command>> commands, const Location& loc)
    : Program(commands, loc), declarations_(declarations) {}