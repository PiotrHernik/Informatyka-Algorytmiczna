#pragma once

#include <string>
#include "Node.hpp"
#include "Enums.hpp"

struct ArgsDeclaration : Node 
{
    ArgsDeclaration(std::string, ArgsDeclarationEnum);
    void setLocation(int, int) override;

    std::string name;
    ArgsDeclarationEnum argsDecEnum;

};

