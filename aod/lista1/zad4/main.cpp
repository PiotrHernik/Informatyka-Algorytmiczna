#include <iostream>
#include <string>
#include <chrono>

#include "Graph.hpp"

int main(int argc, char* argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
    if(argc != 2)
    {
        std::cerr << "Podaj nazwę pliku!" << std::endl;
        return 1;
    }
    Graph g(argv[1]);
    g.GCP();
    
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Czas działania: " << duration.count() << " ms" << std::endl;
    return 0;
}