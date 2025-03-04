#include "ArgDeclaration.hpp"

ArgDeclaration::ArgDeclaration(const std::string& name, DeclarationEnum declEnum, const Location& loc)
    : name_(name), declEnum_(declEnum), location_(loc) {}

const std::string& ArgDeclaration::getName() const
{
    return name_;
}

std::pair<int, int> ArgDeclaration::getLocation() const
{
    return { location_.getLine(), location_.getColumn() };
}
