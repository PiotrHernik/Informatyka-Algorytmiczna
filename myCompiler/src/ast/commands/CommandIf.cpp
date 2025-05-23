#include "CommandIf.hpp"

CommandIf::CommandIf(std::shared_ptr<Condition> cond, std::vector<std::shared_ptr<Command>> commands, const Location& loc)
    : Command(loc), condition_(cond), commands_(commands) {}