#ifndef RADIXHEAPALGORITHM
#define RADIXHEAPALGORITHM

#include "Algorithm.hpp"

class RadixHeapAlgorithm : public Algorithm {
public:
    std::vector<long long int> findPath(Graph &graph, int start, int destination = -1) override;
    
};

#endif // RADIXHEAPALGORITHM