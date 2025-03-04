#include "CommandIfElse.hpp"

CommandIfElse::CommandIfElse(std::shared_ptr<Condition> cond, std::vector<std::shared_ptr<Command>> commandsIf, std::vector<std::shared_ptr<Command>> commandsElse, const Location& loc)
    : Command(loc), condition_(cond), commandsIf_(commandsIf), commandsElse_(commandsElse) {}