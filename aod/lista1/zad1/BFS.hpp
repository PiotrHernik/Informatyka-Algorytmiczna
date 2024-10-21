#pragma once
#include <queue>

#include "Graph.hpp"

class BFS
{
public:
    BFS(Graph* graph);
    ~BFS();
    void bfs(int start);
    void printBFSTree();
private:
    Graph* graph;
    int* distance;
    int* parent;
    std::queue<int> queue;
};