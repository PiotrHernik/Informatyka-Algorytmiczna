#pragma once

#include <string>
#include <vector>
#include <memory>

#include "ProcHead.hpp"
#include "SymbolTable.hpp"

struct Command;
struct Declaration;
struct SymbolTable;


class Procedure
{
public:
    Procedure(std::shared_ptr<ProcHead>, std::vector<std::shared_ptr<Command>>);
    // void fillSymbolTable();
    // void fillArgsAddress(SymbolTable&, std::shared_ptr<ProcCall>);
    // std::vector<std::string> executeCommand(std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int);
    // std::vector<std::string> getProceduresNameCalled() const;
    // int countAsmCommand(std::vector<std::shared_ptr<Procedure>>&);
    // bool isMultiplication();
    // bool isDivOrMod();
private:
    std::shared_ptr<ProcHead> procHead_;
    std::vector<std::shared_ptr<Command>> commands_;
    const long long rntrAddress_;
    SymbolTable symbolTable_;
};