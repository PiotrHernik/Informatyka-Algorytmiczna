#pragma once

#include "IHeuristics.hpp"
#include <stdlib.h>

class ManhatanDistance : public IHeuristics
{
public:
    ManhatanDistance(unsigned int);
// getHeuristic depends on size
    int getHeuristicValue(int64_t, int64_t) const override;

    void setSize(unsigned int);

private:
    unsigned int size_;
};