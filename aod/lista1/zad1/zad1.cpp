#include <iostream>
#include <string>
#include <chrono>

#include "DFS.hpp"
#include "BFS.hpp"

int main(int argc, char *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
    if(argc != 3)
    {
        std::cerr << "Podaj nazwę pliku!" << std::endl;
        return 1;
    }
    Graph g(argv[2]);
    // g.printGraph();
    if(std::string(argv[1]) == "dfs")
    {
        DFS d(&g);
        d.dfs();
        d.printDFSTree();
    }
    else if(std::string(argv[1]) == "bfs")
    {
        BFS b(&g);
        b.bfs(1);
        b.printBFSTree();
    }
    else
    {
        std::cerr << "Podaj poprawny argument!" << std::endl;
        return 1;
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Czas działania: " << duration.count() << " ms" << std::endl;
    return 0;
}