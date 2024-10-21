

#include "StrongComponent.hpp"

StrongComponent::StrongComponent(Graph* graph): graph(graph)
{
    makeTranspose();
}

StrongComponent::~StrongComponent()
{
    delete transposedGraph;
}

void StrongComponent::makeTranspose()
{
    std::vector<std::vector<int>> transposedNeighbours;
    transposedNeighbours.resize(graph->amountOfVertices + 1);
    for (int i = 1; i <= graph->amountOfVertices; i++)
    {
        for (auto j : graph->neighbours[i])
        {
            transposedNeighbours[j].push_back(i);
        }
    }
    transposedGraph = new Graph(graph->amountOfVertices, graph->amountOfEdges, graph->directed, transposedNeighbours);
}

void StrongComponent::findStrongComponents()
{
    DFS dfsModi(transposedGraph);
    DFS dfs(graph);
    // dfs.dfs();
    dfsModi.dfs();

    do{
        auto maxPost = dfsModi.findMaxPost();
        std::vector<int> result;
        result = dfs.dfsModif(maxPost);
        for (auto i : result)
        {
            dfsModi.post[i] = 0;
        }
        strongComponents.push_back(std::move(result));
    } while (dfsModi.findMaxPost() != 0);
    
    printStrongComponents();

}

void StrongComponent::printStrongComponents()
{
    
    std::cout << "Ilość silnie spójnych składowych: " << strongComponents.size() << std::endl;
    for (int i = 0; i < strongComponents.size(); i++)
    {
        std::cout << "Rozmiar " << i + 1 << " składowej: " << strongComponents[i].size() << std::endl;
        if(graph->amountOfVertices <= 200)
        {
            std::cout << "Elementy: ";
            for (auto j : strongComponents[i])
            {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
    
}