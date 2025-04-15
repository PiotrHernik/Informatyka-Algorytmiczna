#pragma once

#include <cstdint>

class IHeuristics
{
public:
    virtual int getHeuristicValue(int64_t currentState, int64_t finalState) const = 0;
};