#include "makeProcedures.hpp"
#include <iostream>

std::vector<std::shared_ptr<Procedure>> makeProcedures(
    std::vector<std::shared_ptr<Procedure>> vec
    , std::shared_ptr<ProcHead> procHead
    , std::vector<std::shared_ptr<Declaration>> declarations
    , std::vector<std::shared_ptr<Command>> commands
    , ProcedureEnum procEnum) 
{
    auto proc = std::make_shared<Procedure>(procHead, declarations, commands, procEnum);
    vec.push_back(proc);
    return vec;
}

std::vector<std::shared_ptr<Procedure>> makeProcedures(
    std::vector<std::shared_ptr<Procedure>> vec
    , std::shared_ptr<ProcHead> procHead
    , std::vector<std::shared_ptr<Command>> commands
    , ProcedureEnum procEnum) 
{
    vec.push_back(std::make_shared<Procedure>(std::move(procHead), commands, procEnum));
    return vec;
}

std::vector<std::shared_ptr<Procedure>> makeProcedures()
{
    std::vector<std::shared_ptr<Procedure>> vec = {};
    return vec;
}