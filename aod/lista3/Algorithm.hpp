#pragma once

#include <vector>
#include "Graph.hpp"

class Algorithm{
public:
    virtual std::vector<long long int> findPath(Graph& graph, int source, int destination = -1) = 0;
};