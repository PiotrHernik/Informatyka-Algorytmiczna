#pragma once

#include <string>
#include <vector>
#include <memory>

#include "ArgDeclaration.hpp"

inline std::vector<std::shared_ptr<ArgDeclaration>> makeArgsDeclaration(
    std::vector<std::shared_ptr<ArgDeclaration>>& argsDeclarations, 
    const std::string& argDec,
    const DeclarationEnum declEnum,
    const Location& loc)
{
    argsDeclarations.push_back(std::make_shared<ArgDeclaration>(argDec, declEnum, loc));
    return argsDeclarations;
}

inline std::vector<std::shared_ptr<ArgDeclaration>> makeArgsDeclaration(
    const std::string& argDec,
    const DeclarationEnum declEnum,
    const Location& loc)
{
    std::vector<std::shared_ptr<ArgDeclaration>> argDeclarations({std::make_shared<ArgDeclaration>(argDec, declEnum, loc)});
    return argDeclarations;
}