#pragma once

#include <memory>

#include "Command.hpp"
#include "Identifier.hpp"

class CommandRead : public Command
{
public:
    CommandRead(std::shared_ptr<Identifier>, const Location&);
private:
    std::shared_ptr<Identifier> identifier_;
};