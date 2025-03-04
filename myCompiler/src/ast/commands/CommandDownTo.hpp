#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Command.hpp"
#include "Value.hpp"

class CommandDownTo : public Command
{
public:
    CommandDownTo(const std::string&, std::shared_ptr<Value>, std::shared_ptr<Value>, std::vector<std::shared_ptr<Command>>, const Location&);
private:
    const std::string pid_;
    std::shared_ptr<Value> from_;
    std::shared_ptr<Value> downto_;
    std::vector<std::shared_ptr<Command>> commands_;
};