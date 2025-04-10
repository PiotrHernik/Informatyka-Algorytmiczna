#pragma once
#include "Graph.hpp"

class DFS
{
public:
    DFS(Graph* graph);
    ~DFS();
    void dfs();
    void printPrePost();
    void printDFSTree();
private:
    void explore(int vertex);
    void previsit(int vertex);
    void postvisit(int vertex);
    

    Graph* graph;
    int* pre;
    int* post;
    int clock = 1;
    bool* visited;
    int* parent;
};