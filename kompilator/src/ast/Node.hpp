#pragma once
#include <string>

struct Node
{
    virtual ~Node() = default;
    virtual std::string doAsm()  const = 0;
    virtual void setLocation(int, int) = 0;

    int line;
    int column;
};