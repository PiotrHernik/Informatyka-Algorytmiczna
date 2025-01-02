#include "makeCommands.hpp"


std::vector<std::shared_ptr<Command>> makeCommands(std::shared_ptr<Command> command)
{
    return std::vector<std::shared_ptr<Command>>({std::move(command)});
}
std::vector<std::shared_ptr<Command>> makeCommands(std::vector<std::shared_ptr<Command>> vec, std::shared_ptr<Command> command)
{
    vec.push_back(std::move(command));
    return vec;
}