#include <iostream>

#include "DFS.hpp"

DFS::DFS(Graph* graph): graph(graph)
{
    // pre = new int[graph->amountOfVertices + 1];
    post = new int[graph->amountOfVertices + 1];
    visited = new bool[graph->amountOfVertices + 1];
    parent = new int[graph->amountOfVertices + 1];
    for (auto i = 1; i <= graph->amountOfVertices; i++)
    {
        visited[i] = false;
        parent[i] = 0;
    }
}

DFS::~DFS()
{
    // delete[] pre;
    delete[] post;
    delete[] visited;
    delete[] parent;
}

void DFS::dfs()
{
    for (auto i = 1; i <= graph->amountOfVertices; i++)
    {
        if (!visited[i])
        {
            explore(i);
        }
    }
}

std::vector<int> DFS::dfsModif(int vertex)
{
    std::vector<int> result;
    exploreModif(vertex, result);
    return result;
}

void DFS::exploreModif(int vertex, std::vector<int>& result)
{
    visited[vertex] = true;
    result.push_back(vertex);
    for (auto i : graph->neighbours[vertex])
    {
        if (!visited[i])
        {
            exploreModif(i, result);
        }
    }
}

void DFS::explore(int vertex)
{
    visited[vertex] = true;
    previsit(vertex);
    for (auto i : graph->neighbours[vertex])
    {
        if (!visited[i])
        {
            parent[i] = vertex;
            explore(i);
        }
    }
    postvisit(vertex);
}

void DFS::previsit(int vertex)
{
    // std::cout<<vertex<<", ";
    // pre[vertex] = clock;
    clock++;
}

void DFS::postvisit(int vertex)
{
    post[vertex] = clock;
    clock++;
}

void DFS::printPrePost()
{
    for (auto i = 1; i <= graph->amountOfVertices; i++)
    {
        // std::cout << i << ": " << pre[i] << " " << post[i] << std::endl;
    }
}

void DFS::printDFSTree()
{
    std::cout<<"Vertex: Parent"<<std::endl;
    for (auto i = 1; i <= graph->amountOfVertices; i++)
    {
        std::cout << i << ": " << parent[i] << std::endl;
    }
}

int DFS::findMaxPost()
{
    int max = 0;
    int maxIndex = 0;
    for (auto i = 1; i <= graph->amountOfVertices; i++)
    {
        if (post[i] > max)
        {
            max = post[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

