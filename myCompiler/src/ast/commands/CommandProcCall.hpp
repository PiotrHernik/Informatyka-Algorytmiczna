#pragma once

#include <memory>

#include "Command.hpp"
#include "procCall/ProcCall.hpp"

class CommandProcCall : public Command
{
public:
    CommandProcCall(std::shared_ptr<ProcCall>, const Location&);
private:
    std::shared_ptr<ProcCall> procCall_;
};