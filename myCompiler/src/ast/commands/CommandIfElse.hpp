#pragma once

#include <vector>

#include "Command.hpp"
#include "Condition.hpp"

class CommandIfElse : public Command
{
public: 
    CommandIfElse(std::shared_ptr<Condition>, std::vector<std::shared_ptr<Command>>, std::vector<std::shared_ptr<Command>>, const Location&);
private:
    std::shared_ptr<Condition> condition_;
    std::vector<std::shared_ptr<Command>> commandsIf_;
    std::vector<std::shared_ptr<Command>> commandsElse_;
};