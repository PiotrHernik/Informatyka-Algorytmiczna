#include <identifiers/IdentifierPid.hpp>

IdentifierPid::IdentifierPid(const std::string& name, const Location& loc) 
    : Identifier(name, loc) {}

std::vector<std::string> IdentifierPid::getAddress() const
{
    std::vector<std::string> vec;
    return vec;
}