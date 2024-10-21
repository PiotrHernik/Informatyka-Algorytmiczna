#include <iostream>

#include "DFS.hpp"

DFS::DFS(Graph* graph): graph(graph)
{
    pre = new int[graph->amountOfVertices + 1];
    post = new int[graph->amountOfVertices + 1];
    visited = new bool[graph->amountOfVertices + 1];
    visited2 = new bool[graph->amountOfVertices + 1];
    parent = new int[graph->amountOfVertices + 1];

    for (auto i = 1; i <= graph->amountOfVertices; i++)
    {
        visited[i] = false;
        visited2[i] = false;
        parent[i] = 0;
    }
}

DFS::~DFS()
{
    delete[] pre;
    delete[] post;
    delete[] visited;
    delete[] visited2;
    delete[] parent;
}

void DFS::dfs()
{
    for (auto i = 1; i <= graph->amountOfVertices; i++)
    {
        if (!visited[i] && !isCyclic)
        {
            explore(i);
            if(isCyclic)
            {
                return;
            }
        }
    }
    std::cout<<"Graph is acyclic"<<std::endl;
    if(graph->amountOfVertices <= 200)
    {
        std::cout<<"Topological order: ";
        while (!topologicalOrder.empty())
        {
            std::cout << topologicalOrder.top() << ", ";
            topologicalOrder.pop();
        }
        std::cout << std::endl;
    }
}

void DFS::explore(int vertex)
{
    // for(auto i = 1; 1 <= graph->amountOfVertices; i++)
    // {
    //     std::cout<<visited[i]<<" ";
    // }

    if(isCyclic)
    {
        return;
    }
    visited2[vertex] = true;
    visited[vertex] = true;
    previsit(vertex);
    for (auto i : graph->neighbours[vertex])
    {
        if(visited2[i])
        {
            isCyclic = true;
            // std::cout<<"Graph is cyclic"<<std::endl;
            return;
        }
        if (!visited[i])
        {
            parent[i] = vertex;
            explore(i);
            if (isCyclic)
                return;
        }
    }
    postvisit(vertex);
    visited2[vertex] = false;
}

void DFS::previsit(int vertex)
{
    // std::cout<<vertex<<", ";
    pre[vertex] = clock;
    clock++;
}

void DFS::postvisit(int vertex)
{
    topologicalOrder.push(vertex);
    post[vertex] = clock;
    clock++;
}

// void DFS::printPrePost()
// {
//     for (auto i = 1; i <= graph->amountOfVertices; i++)
//     {
//         std::cout << i << ": " << pre[i] << " " << post[i] << std::endl;
//     }
// }

void DFS::printDFSTree()
{
    if(isCyclic)
    {
        return;
    }
    std::cout<<"Vertex: Parent"<<std::endl;
    for (auto i = 1; i <= graph->amountOfVertices; i++)
    {
        std::cout << i << ": " << parent[i] << std::endl;
    }
}

