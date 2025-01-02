#pragma once
#include <string>

struct Node
{
    virtual ~Node() = default;
    virtual std::string doAsm()  const = 0;
};