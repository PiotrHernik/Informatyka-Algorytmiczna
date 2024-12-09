#include <iostream>
#include <limits>
#include "Graph.hpp"
#include "PriorityQueue.hpp"


Graph::Graph(Parser parser){
    minCost = std::numeric_limits<int>::max();
    minVertex = std::numeric_limits<int>::max();
    maxVertex = 0;

    auto sizeAndEdges = parser.readEdgesFromFile();

    vertexSize = sizeAndEdges.first.first;
    edgesSize = sizeAndEdges.first.second;
    auto edges = sizeAndEdges.second;
    if(edges.empty()) return;
    neighborhood.resize(vertexSize+1);

    for(const auto& edge : edges){
        int from = std::get<0>(edge);
        int to = std::get<1>(edge);
        long long int cost = std::get<2>(edge);

        if(from > maxVertex) maxVertex = from;
        if(from < minVertex) minVertex = from;
        if(minCost > cost) minCost = cost;
        if(maxCost < cost) maxCost = cost;
        neighborhood[from].emplace_back(to,cost);
    }
}

std::vector<std::vector<std::pair<int, long long int>>> Graph::getNeighborhood(){
    return neighborhood;
};

int Graph::getVertexSize() { return vertexSize; }

int Graph::getEdgesSize() { return edgesSize; } 

int Graph::getMinCost() { return minCost; }

int Graph::getMaxCost() { return maxCost; }

int Graph::getMinVertex() { return minVertex; }

int Graph::getMaxVertex() { return maxVertex; }
