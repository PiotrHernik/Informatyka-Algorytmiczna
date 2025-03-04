#pragma once

#include <vector>
#include <memory>
#include "Command.hpp"
#include "Procedure.hpp"

class Program
{
public:
    Program(std::vector<std::shared_ptr<Command>>, const Location&);
    virtual ~Program() = default;
    // virtual void fillSymbolTable() = 0;
    // virtual void executeCommand(std::vector<std::shared_ptr<Procedure>>&);
    // bool areMuliplyProcedure(std::vector<std::shared_ptr<Procedure>>&) const;
    // std::vector<std::string> findProcedureCallName() const;
    // std::vector<std::string> makeProceduresGraph(std::vector<std::shared_ptr<Procedure>>&, std::vector<std::string>&) const;

private:
    std::vector<std::shared_ptr<Command>> commands_;
    std::string name_;
    SymbolTable symbolTable_;
    Location location_;
};