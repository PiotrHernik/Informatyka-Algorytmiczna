#include "ArgsDeclaration.hpp"

ArgsDeclaration::ArgsDeclaration(std::string name, ArgsDeclarationEnum argsDecEnum)
    : name(std::move(name)), argsDecEnum(argsDecEnum){}

std::string ArgsDeclaration::doAsm() const {
    return std::string("ArgsDec");
}

void ArgsDeclaration::setLocation(int lin, int col)
{
    line = lin;
    column = col;
}