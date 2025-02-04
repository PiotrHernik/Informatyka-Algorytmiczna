#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Node.hpp"
#include "Enums.hpp"
#include "ArgsDeclaration.hpp"
#include "../SymbolTable/SymbolTable.hpp"

struct ProcHead : Node 
{
    ProcHead(std::string, std::vector<std::shared_ptr<ArgsDeclaration>>);
    void fillSymbolTable(SymbolTable& symbTab);
    void setLocation(int, int) override;

    std::string name;
    std::vector<std::shared_ptr<ArgsDeclaration>> argsDecl;
};