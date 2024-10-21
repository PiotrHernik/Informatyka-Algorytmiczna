#include "BFS.hpp"

BFS::BFS(Graph* graph): graph(graph)
{
    distance = new int[graph->amountOfVertices + 1];
    parent = new int[graph->amountOfVertices + 1];
    for (auto i = 1; i <= graph->amountOfVertices; i++)
    {
        distance[i] = -1;
        parent[i] = 0;
    }
}

BFS::~BFS()
{
    delete[] distance;
    delete[] parent;
}

void BFS::bfs(int start)
{
    std::cout << "Starting BFS from: " << start << std::endl;
    distance[start] = 0;
    queue.push(start);
    while (!queue.empty())
    {
        int vertex = queue.front();
        queue.pop();
        for (auto i : graph->neighbours[vertex])
        {
            if (distance[i] == -1)
            {
                std::cout << i << ", ";
                distance[i] = distance[vertex] + 1;
                parent[i] = vertex;
                queue.push(i);
            }
        }
    }
}

void BFS::printBFSTree()
{
    std::cout << "Vertex: Distance Parent" << std::endl;
    for (auto i = 1; i <= graph->amountOfVertices; i++)
    {
        std::cout << i << ": " << distance[i] << " " << parent[i] << std::endl;
    }
}