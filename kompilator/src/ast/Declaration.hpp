#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Node.hpp"
#include "Identifier.hpp"
#include "Enums.hpp"

struct Declaration : Node 
{
    Declaration(const std::string, DeclarationEnum);
    Declaration(const std::string, DeclarationEnum, long long num1, long long num2);
    std::string doAsm() const override;
    void setLocation(int, int) override;

    std::string name;
    DeclarationEnum decEnum;
    long long num1;
    long long num2;
};