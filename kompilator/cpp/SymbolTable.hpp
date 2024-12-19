#pragma once

#include <set>
#include <unordered_map>
#include "ast.hpp"

class SymbolTable
{
public:
    bool isInitialized(std::string);
    bool isDeclared(std::string);

private:
    std::set<Identifier> variables;
    std::unordered_map<Identifier, long long> variable_adress;
};