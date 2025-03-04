#pragma once

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

#include "Procedure.hpp"
#include "ProcedureWithDeclaration.hpp"
#include "ProcedureWithoutDecl.hpp"
#include "declarations/Declaration.hpp"
#include "ProcHead.hpp"
#include "Command.hpp"

inline std::vector<std::shared_ptr<Procedure>> makeProcedures(
    std::vector<std::shared_ptr<Procedure>> vec
    , std::shared_ptr<ProcHead> procHead
    , std::vector<std::shared_ptr<Declaration>> declarations
    , std::vector<std::shared_ptr<Command>> commands) 
{
    auto proc = std::make_shared<ProcedureWithDeclaration>(procHead, declarations, commands);
    vec.push_back(proc);
    return vec;
}

inline std::vector<std::shared_ptr<Procedure>> makeProcedures(
    std::vector<std::shared_ptr<Procedure>> vec
    , std::shared_ptr<ProcHead> procHead
    , std::vector<std::shared_ptr<Command>> commands) 
{
    vec.push_back(std::make_shared<ProcedureWithoutDecl>(std::move(procHead), commands));
    return vec;
}

inline std::vector<std::shared_ptr<Procedure>> makeProcedures()
{
    std::vector<std::shared_ptr<Procedure>> vec = {};
    return vec;
}