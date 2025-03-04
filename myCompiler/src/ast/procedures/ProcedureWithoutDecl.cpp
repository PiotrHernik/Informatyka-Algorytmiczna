#include "ProcedureWithoutDecl.hpp"

ProcedureWithoutDecl::ProcedureWithoutDecl(std::shared_ptr<ProcHead> procHead, std::vector<std::shared_ptr<Command>> commands)
    : Procedure(procHead, commands) {}