#include <iostream>

#include "makeDeclarations.hpp"

std::vector<std::shared_ptr<Declaration>> makeDeclaration(const std::string name, std::initializer_list<long long> list)
{
    std::vector<std::shared_ptr<Declaration>> vec;
    if(list.size() == 0) vec.push_back(std::make_shared<Declaration>(name, DeclarationEnum::PID));
    else if(list.size() == 2)  
    {
        auto it = list.begin();
        vec.push_back(std::make_shared<Declaration>(name, DeclarationEnum::TABLE, *it, *(it+1)));
    }
    else
        throw std::invalid_argument("Ivalid number of arguments");
    return vec;
}

std::vector<std::shared_ptr<Declaration>> makeDeclaration(
    std::vector<std::shared_ptr<Declaration>> vec, 
    const std::string name, 
    std::initializer_list<long long> list){
    if(list.size() == 0) 
        vec.push_back(std::make_shared<Declaration>(name, DeclarationEnum::PID));
    else if(list.size() == 2) 
    {
        auto it = list.begin();
        vec.push_back(std::make_shared<Declaration>(name, DeclarationEnum::TABLE, *it, *(it+1)));
    }
    else 
        throw std::invalid_argument("Invalid number of argument");
    return vec;
}