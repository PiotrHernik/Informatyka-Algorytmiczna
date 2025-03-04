#pragma once

#include <string>
#include <utility>

#include "Location.hpp"
#include "Enums.hpp"

/*
    Arguments between '(' ')' in procHead definition
*/
class ArgDeclaration
{
public:
    ArgDeclaration(const std::string& name, DeclarationEnum declEnum, const Location& loc);

    const std::string& getName() const;
    std::pair<int, int> getLocation() const;

private:
    std::string name_;
    DeclarationEnum declEnum_;
    Location location_;
};
