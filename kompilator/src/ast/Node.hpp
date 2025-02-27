#pragma once
#include <string>

struct Node
{
    virtual ~Node() = default;
    virtual void setLocation(int, int) = 0;

    int line;
    int column;
};