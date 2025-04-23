#pragma once

#include "IHeuristics.hpp"
#include <stdlib.h>
#include <vector>

class LinearConflicts : public IHeuristics
{
public:
    LinearConflicts(unsigned int);
    // getHeuristic depends on size
    int getHeuristicValue(int64_t, int64_t) const override;

    void setSize(unsigned int);
private:
    // int computeLinearConflictsRow(const std::vector<int>&) const;

    unsigned int size_;
};