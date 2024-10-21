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

Graph::~Graph() {}

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

void Graph::GCP() noexcept
{
    std::vector<int> color(amountOfVertices + 1, 0);
    std::list<size_t> queue;

    for(size_t i = 1; i <= amountOfVertices; i++)
    {
        if(color[i] == 0)
        {
            color[i] = 1;
            queue.push_back(i);

            while(!queue.empty())
            {
                size_t v = queue.front();
                queue.pop_front();

                for (size_t adjacent : neighbours[v])
                {
                    if(color[adjacent] == color[v])
                    {
                        std::cout << "NIE!" << std::endl;
                        return;
                    }
                    else if(color[adjacent] == 0)
                    {
                        color[adjacent] = -color[v];
                        queue.push_back(adjacent);
                    }
                }
            }
        }
    }

    std::cout << "TAK!" << std::endl;

    if(amountOfVertices <= 200)
    {
        std::cout << "Red vertices:" << std::endl;
        for(int i = 1; i <= amountOfVertices; i++)
        {
            if(color[i] == 1)
            {
                std::cout << i << " ";
            }
        }

        std::cout << std::endl << "Green vertices:" << std::endl;
        for(int i = 1; i <= amountOfVertices; i++)
        {
            if(color[i] == -1)
            {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }
}

// Metoda do wypisania grafu
void Graph::printGraph()
{
    for (size_t i = 1; i <= amountOfVertices; ++i)
    {
        std::cout << "Vertex " << i << ":";
        for (int neighbour : neighbours[i])
        {
            std::cout << " " << neighbour;
        }
        std::cout << std::endl;
    }
}
