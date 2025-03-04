#pragma once

#include <vector>

#include "Command.hpp"
#include "Condition.hpp"

class CommandWhile : public Command
{
public:
    CommandWhile(std::shared_ptr<Condition>, std::vector<std::shared_ptr<Command>>, const Location&);
private:
    std::shared_ptr<Condition> condition_;
    std::vector<std::shared_ptr<Command>> commands_;
};