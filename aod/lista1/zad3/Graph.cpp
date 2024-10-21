#include <fstream>
#include <sstream>

#include "Graph.hpp"

Graph::Graph(std::string filename)
{
    std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Nie można otworzyć pliku!" << std::endl;
            return;
        }
        makeNeighbours(file);
        file.close();
}

Graph::Graph(int vertices, int edges, bool directed, std::vector<std::vector<int>> neighbours): neighbours(neighbours), 
        amountOfVertices(vertices), 
        amountOfEdges(edges), 
        directed(directed)
{
}

Graph::~Graph()
{
}

void Graph::makeNeighbours(std::ifstream& file)
{
    char graphType;
    file >> graphType;
    directed = (graphType == 'D');
    file >> amountOfVertices;
    file >> amountOfEdges;
    neighbours.resize(amountOfVertices + 1);
    for (int i = 0; i < amountOfEdges; i++)
    {
        int vertex1, vertex2;
        file >> vertex1 >> vertex2;
        neighbours[vertex1].push_back(vertex2);
        if (!directed)
        {
            neighbours[vertex2].push_back(vertex1);
        }
    }
}

void Graph::printGraph()
{
    for (auto i = 1; i <= amountOfVertices; i++)
    {
        std::cout << i << ": ";
        for (auto j : neighbours[i])
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
