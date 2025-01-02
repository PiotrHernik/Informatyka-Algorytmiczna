#include "makeArgsDeclaration.hpp"

std::vector<std::shared_ptr<ArgsDeclaration>> makeArgsDeclaration(
    std::vector<std::shared_ptr<ArgsDeclaration>>& vec, 
    const std::string& argDec, 
    ArgsDeclarationEnum argDecEnum)
{
    vec.push_back(std::make_shared<ArgsDeclaration>(argDec, argDecEnum));
    return vec;
}

std::vector<std::shared_ptr<ArgsDeclaration>> makeArgsDeclaration(
    const std::string& argDec, 
    ArgsDeclarationEnum argsDecEnum)
{
    std::vector<std::shared_ptr<ArgsDeclaration>> vec({std::make_shared<ArgsDeclaration>(argDec, argsDecEnum)});
    return vec;
}