#pragma once

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

#include "declarations/Declaration.hpp"
#include "declarations/DeclarationPid.hpp"
#include "declarations/DeclarationTable.hpp"
#include "Location.hpp"

inline std::vector<std::shared_ptr<Declaration>> makeDeclaration(const std::string& name, std::initializer_list<long long> list, const Location& loc)
{
    std::vector<std::shared_ptr<Declaration>> vec;
    if(list.size() == 0) vec.push_back(std::make_shared<DeclarationPid>(name, loc));
    else 
    {
        auto it = list.begin();
        vec.push_back(std::make_shared<DeclarationTable>(name, *it, *(it+1), loc));
    }
    return vec;
}

inline std::vector<std::shared_ptr<Declaration>> makeDeclaration(
    std::vector<std::shared_ptr<Declaration>> vec, 
    const std::string name, 
    std::initializer_list<long long> list,
    const Location& loc){
    if(list.size() == 0) 
        vec.push_back(std::make_shared<DeclarationPid>(name, loc));
    else
    {
        auto it = list.begin();
        vec.push_back(std::make_shared<DeclarationTable>(name, *it, *(it+1), loc));
    }

    return vec;
}
