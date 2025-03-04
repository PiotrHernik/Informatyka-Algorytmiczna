#pragma once 

#include <memory>

#include "Command.hpp"
#include "Identifier.hpp"
#include "Expression.hpp"

class CommandAssign : public Command
{
public:
    CommandAssign(std::shared_ptr<Identifier>, std::shared_ptr<Expression>, const Location&);
private:
    std::shared_ptr<Identifier> identifier_;
    std::shared_ptr<Expression> expression_;
};