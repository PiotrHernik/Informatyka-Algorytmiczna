#pragma once

#include "Node.hpp"
#include "Enums.hpp"
#include <string>

struct Identifier : Node {
    Identifier(std::string pid, IdentifierEnum idEnum);
    Identifier(std::string pid1, std::string pid2, IdentifierEnum idEnum);
    Identifier(std::string pid, long long num, IdentifierEnum idEnum);
    std::string doAsm() const override;
    void setLocation(int, int) override;

    IdentifierEnum idEnum;
    std::string name1;
    std::string name2;
    long long num;
    int line;
    int column;
};

