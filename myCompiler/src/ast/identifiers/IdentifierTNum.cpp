#include <identifiers/IdentifierTNum.hpp>

#include "Location.hpp"

IdentifierTNum::IdentifierTNum(const std::string& name, const long long num, const Location& loc) 
    : Identifier(name, loc), num_(num) {}

long long IdentifierTNum::getNum() const
{
    return num_;
}

std::vector<std::string> IdentifierTNum::getAddress() const
{
    std::vector<std::string> vec;
    return vec;
}
