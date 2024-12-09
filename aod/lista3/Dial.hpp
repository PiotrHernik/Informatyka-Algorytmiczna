
#ifndef DIAL_H
#define DIAL_H

#include "Algorithm.hpp"

class Dial : public Algorithm{
public:
    std::vector<long long int> findPath(Graph& graph, int source, int destination = -1) override;

};

#endif //DIAL_H