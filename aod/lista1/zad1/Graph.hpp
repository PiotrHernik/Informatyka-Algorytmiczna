#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

class Graph
{
public:
    Graph(std::string file);
    ~Graph();
    void printGraph();
    friend class DFS;
    friend class BFS;
private:
    void makeNeighbours(std::ifstream& file);

    std::map<int, std::vector<int>> neighbours;
    int amountOfVertices;
    int amountOfEdges;
    bool directed;

};