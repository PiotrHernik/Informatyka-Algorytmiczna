#pragma once

#include <memory>

#include "Command.hpp"
#include "Value.hpp"

class CommandWrite : public Command
{
public:
    CommandWrite(std::shared_ptr<Value>, const Location&);
private:
    std::shared_ptr<Value> value_;
};