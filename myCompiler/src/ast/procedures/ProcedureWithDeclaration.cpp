#include "ProcedureWithDeclaration.hpp"

ProcedureWithDeclaration::ProcedureWithDeclaration(std::shared_ptr<ProcHead> procHead, std::vector<std::shared_ptr<Declaration>> declarations, std::vector<std::shared_ptr<Command>> commands)
    : Procedure(procHead, commands), declarations_(declarations) {}