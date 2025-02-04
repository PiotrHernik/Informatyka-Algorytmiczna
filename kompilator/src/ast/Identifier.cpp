#include "Identifier.hpp"
#include <iostream>

Identifier::Identifier(std::string pid, IdentifierEnum idEnum) : name1(pid), idEnum(idEnum)
{
}
Identifier::Identifier(std::string pid1, std::string pid2, IdentifierEnum idEnum) : name1(pid1), name2(pid2), idEnum(idEnum)
{
}
Identifier::Identifier(std::string pid, long long num, IdentifierEnum idEnum) : name1(pid), num(num), idEnum(idEnum)
{
}

void Identifier::setLocation(int lin, int col)
{
    line = lin;
    column = col;
}