#include "CommandForTo.hpp"

CommandForTo::CommandForTo(const std::string& pid, std::shared_ptr<Value> from, std::shared_ptr<Value> to, std::vector<std::shared_ptr<Command>> commands, const Location& loc)
    : Command(loc), pid_(pid), from_(from), to_(to), commands_(commands) {}