#pragma once

#include "Program.hpp"

#include <vector>
#include <memory>

#include "Command.hpp"
#include "Procedure.hpp"

class ProgramWithoutDeclarations : public Program
{
public:
    ProgramWithoutDeclarations(std::vector<std::shared_ptr<Command>>, const Location&);
    // virtual void fillSymbolTable() = 0;
    // virtual void executeCommand(std::vector<std::shared_ptr<Procedure>>&);
    // bool areMuliplyProcedure(std::vector<std::shared_ptr<Procedure>>&) const;
    // std::vector<std::string> findProcedureCallName() const;
    // std::vector<std::string> makeProceduresGraph(std::vector<std::shared_ptr<Procedure>>&, std::vector<std::string>&) const;
};