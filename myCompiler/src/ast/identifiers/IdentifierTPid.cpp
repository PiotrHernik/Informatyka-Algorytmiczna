#include <identifiers/IdentifierTPid.hpp>

IdentifierTPid::IdentifierTPid(const std::string& name, const std::string& name2, const Location& loc)
    : Identifier(name, loc), name2_(name2) {}

std::string IdentifierTPid::getName2() const
{
    return name2_;
}

std::vector<std::string> IdentifierTPid::getAddress() const
{
    std::vector<std::string> vec;
    return vec;
}