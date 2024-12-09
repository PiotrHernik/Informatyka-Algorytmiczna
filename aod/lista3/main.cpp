#include <string>
#include <cstring>
#include <iostream>
#include <limits>
#include <fstream>
#include <list>
#include <chrono>
#include <iostream>
#include <random>
#include <filesystem>

#include "Parser.hpp"
#include "Graph.hpp"
#include "Dial.hpp"
#include "RadixHeapAlgorithm.hpp"
#include "Algorithm.hpp"
#include "Dijkstra.hpp"

int main(int argc, char* argv[])
{
    std::string outputFileName;

    outputFileName = argv[7];

    
    Parser parser(argc, argv);
    Graph graph(parser);
    std::unique_ptr<Algorithm> algorithm;
    std::ofstream resultsFile(outputFileName);
    auto start = graph.getMinVertex();

    
    if(strcmp(argv[4],"-ss") == 0)
    {
        short mode = 4;
        auto sourceList = parser.readStartPoint();
        if(strcmp(argv[1], "dijkstra") == 0)
        {
            algorithm = std::make_unique<Dijkstra>();
        }
        else if(strcmp(argv[1], "dial") == 0)
        {
            algorithm = std::make_unique<Dial>();
        }
        else if(strcmp(argv[1], "radixheap") == 0)
        {
            algorithm = std::make_unique<RadixHeapAlgorithm>();
        }

        auto start = std::chrono::steady_clock::now();
        size_t listSize = sourceList.size();
        for(auto s : sourceList)
        {
            sourceList.pop_back();
            auto distance = algorithm->findPath(graph, s);
        }
        auto end = std::chrono::steady_clock::now();

        double t = (double) std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() / (double)listSize;
        resultsFile << "p res sp ss dijkstra\n";
        resultsFile << "f " << argv[3] << " " << argv[5] << '\n';
        resultsFile << "g " << graph.getVertexSize() << " " << graph.getEdgesSize() << " " << graph.getMinCost() << " " << graph.getMaxCost() << "\n";
        resultsFile << "t " << t / 1000;
        std::cout << std::endl << t << std::endl;
    }
    else
    {
        short mode;
        auto pairs = parser.readP2P();
        if(strcmp(argv[1], "dijkstra") == 0)
        {
            algorithm = std::make_unique<Dijkstra>();
        }
        else if(strcmp(argv[1], "dial") == 0)
        {
            algorithm = std::make_unique<Dial>();
        }
        else if(strcmp(argv[1], "radixheap") == 0)
        {
            algorithm = std::make_unique<RadixHeapAlgorithm>();
        }
        resultsFile << "f " << argv[3] << " " << argv[5] << '\n';
        resultsFile << "g " << graph.getVertexSize() << " " << graph.getEdgesSize() << " " << graph.getMinCost() << " " << graph.getMaxCost() << "\n";
        while(!pairs.empty())
        {
            std::cout << "Pairs left:" << pairs.size() << std::endl;
            size_t s = pairs.back().first;
            size_t f = pairs.back().second;
            pairs.pop_back();
            auto d = algorithm->findPath(graph, s, f);
            resultsFile << "d " << s << " " << f << " " << d[0] << '\n';
        }
    }
  
    return 0;
}
