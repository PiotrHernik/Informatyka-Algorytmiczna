#include "CommandDownTo.hpp"

CommandDownTo::CommandDownTo(const std::string& pid, std::shared_ptr<Value> from, std::shared_ptr<Value> downto, std::vector<std::shared_ptr<Command>> commands, const Location& loc)
    : Command(loc), pid_(pid), from_(from), downto_(downto), commands_(commands) {}