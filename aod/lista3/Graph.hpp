#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include "Parser.hpp"


typedef std::pair<int, long long int> Edge;

class Graph{
public:
    Graph(Parser);
    std::vector<long long int> dijkstra(int start) ;
    std::vector<std::vector<std::pair<int, long long int>>> getNeighborhood();
    int getMaxCost();
    int getVertexSize();
    int getEdgesSize();
    int getMinCost();
    int getMinVertex();
    int getMaxVertex();


private:
    std::vector<std::vector<std::pair<int, long long int>>> neighborhood;
    int vertexSize;
    int edgesSize;
    int minCost = 0;
    int maxCost = 0;
    int minVertex;
    int maxVertex;
    

};