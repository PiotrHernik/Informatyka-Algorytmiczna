#include "CommandProcCall.hpp"

CommandProcCall::CommandProcCall(std::shared_ptr<ProcCall> procCall, const Location& loc)
    : Command(loc), procCall_(procCall) {}