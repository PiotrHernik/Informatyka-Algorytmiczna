#pragma once
#include "Graph.hpp"

class DFS
{
public:
    DFS(Graph* graph);
    ~DFS();
    void dfs();
    std::vector<int> dfsModif(int vertex);
    void printPrePost();
    void printDFSTree();
    friend class StrongComponent;
private:
    void explore(int vertex);
    void exploreModif(int vertex, std::vector<int>& result);
    void previsit(int vertex);
    void postvisit(int vertex);
    int findMaxPost();
    

    Graph* graph;
    // int* pre;
    int* post;
    int clock = 1;
    bool* visited;
    int* parent;
};