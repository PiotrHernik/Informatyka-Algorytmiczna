
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Algorithm.hpp"

class Dijkstra : public Algorithm{
public:
    std::vector<long long int> findPath(Graph& graph, int source, int destination = -1) override;

};

#endif //DIJKSTRA_H