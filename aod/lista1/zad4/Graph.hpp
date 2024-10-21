#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>

class Graph
{
public:
    Graph(std::string filename);

    ~Graph();

    void GCP() noexcept;

    void printGraph();

private:
    void makeNeighbours(std::ifstream& file);

    std::vector<std::vector<int>> neighbours;
    int amountOfVertices;
    int amountOfEdges;
    bool directed;
};
