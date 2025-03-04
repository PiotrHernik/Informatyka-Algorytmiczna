#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Command.hpp"
#include "Value.hpp"

class CommandForTo : public Command
{
public:
    CommandForTo(const std::string&, std::shared_ptr<Value>, std::shared_ptr<Value>, std::vector<std::shared_ptr<Command>>, const Location&);
private:
    const std::string pid_;
    std::shared_ptr<Value> from_;
    std::shared_ptr<Value> to_;
    std::vector<std::shared_ptr<Command>> commands_;
};