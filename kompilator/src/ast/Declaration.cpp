#include <iostream>

#include "Declaration.hpp"
#include "../ErrorClass/Error.hpp"

Declaration::Declaration(const std::string name, DeclarationEnum decEnum)
    : name(name), decEnum(decEnum), num1(0), num2(0){}

Declaration::Declaration(const std::string name, DeclarationEnum decEnum, long long num1, long long num2)
    : name(name), decEnum(decEnum), num1(num1), num2(num2)
    {
        if(num1 > num2) 
        {
            std::string errMsg = "num1 > num2, " + std::to_string(line) + ":" + std::to_string(column);
            Error err(errMsg);
            err.notifyError();
        }
    }

std::string Declaration::doAsm() const
{
    return std::string("Declaration");
}

void Declaration::setLocation(int lin, int col)
{
    line = lin;
    column = col;
}