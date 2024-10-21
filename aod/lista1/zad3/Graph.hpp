#pragma once

#include <iostream>
#include <string>
#include <vector>

class Graph
{
public:
    Graph(std::string file);
    Graph(int vertices, int edges, bool directed, std::vector<std::vector<int>> neighbours);
    ~Graph();
    void printGraph();
    friend class DFS;
    friend class BFS;
    friend class StrongComponent;
private:
    void makeNeighbours(std::ifstream& file);

    std::vector<std::vector<int>> neighbours;
    int amountOfVertices;
    int amountOfEdges;
    bool directed;

};