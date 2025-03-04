#pragma once

#include <string>
#include <vector>
#include <memory>
#include <utility>

// #include "Node.hpp"
// #include "Enums.hpp"
#include "ArgDeclaration.hpp"
#include "Location.hpp"
// #include "../SymbolTable/SymbolTable.hpp"

class ProcHead 
{
public:
    ProcHead(std::string&, std::vector<std::shared_ptr<ArgDeclaration>>, Location&);
    // void fillSymbolTable(SymbolTable& symbTab);
    std::pair<int,int> getLocation() const;
    std::string getName() const;
private:
    const std::string name_;
    std::vector<std::shared_ptr<ArgDeclaration>> argsDecl_;
    Location location_;
};