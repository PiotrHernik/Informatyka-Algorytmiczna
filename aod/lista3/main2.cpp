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

std::vector<int> findRandom(int);
std::vector<std::pair<int, int>> findRandomPairs(int vertexSize);

int main(int argc, char* argv[])
{
    Parser parser(argc, argv);
    Graph graph(parser);
    std::unique_ptr<Algorithm> algorithm;

    auto minVertex = graph.getMinVertex();
    auto maxVertex = graph.getMaxVertex();
    auto randomStart = findRandom(graph.getMaxVertex());

    std::vector<std::string> algorithms = {"dijkstra", "dial", "radixheap"};

    for(const auto& alg : algorithms){
        std::string outputFile = alg + std::string(".min.ss.res");
        std::ofstream resultsFile(outputFile, std::ios::app);

        if(alg == "dijkstra")
        {
            algorithm = std::make_unique<Dijkstra>();        
        }
        else if(alg == "dial")
        {
            algorithm = std::make_unique<Dial>();
        }
        else if(alg == "radixheap")
        {
            algorithm = std::make_unique<RadixHeapAlgorithm>();
        }

        auto start = std::chrono::steady_clock::now();
        algorithm->findPath(graph, minVertex);
        auto end = std::chrono::steady_clock::now();

        double t = (double) std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
        resultsFile << "File: " << argv[1] << "\n";
        resultsFile << "p res sp ssMin " << alg << "\n" ;
        resultsFile << "g " << graph.getVertexSize() << " " << graph.getEdgesSize() << " " << graph.getMinCost() << " " << graph.getMaxCost() << "\n";
        resultsFile << "t " << t / 1000 << "\n";
        resultsFile.close();

        outputFile = alg + std::string(".rand.ss.res");
        start = std::chrono::steady_clock::now();
        for(auto startPoint : randomStart){
            algorithm->findPath(graph, startPoint);
        }
        end = std::chrono::steady_clock::now();

        resultsFile.open(outputFile, std::ios::app);
        t = (double) std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() / randomStart.size();

        resultsFile << "File: " << argv[1] << "\n";
        resultsFile << "p res sp ssRand "  << alg << "\n" ;
        resultsFile << "g " << graph.getVertexSize() << " " << graph.getEdgesSize() << " " << graph.getMinCost() << " " << graph.getMaxCost() << "\n";
        resultsFile << "t " << t / 1000 <<"\n";
        resultsFile.close();


    }
        

        // if(my){
        //     std::cout<<"jestem w moim"<<std::endl;
        //     algorithm = std::make_unique<RadixHeapAlgorithm>();

        //     auto size = randomStart.size();
        //     auto minVertex = graph.getMinVertex();

        //     auto start = std::chrono::steady_clock::now();
        //     algorithm->findPath(graph, minVertex);
        //     auto end = std::chrono::steady_clock::now();

        //     double time = (double) std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

        //     std::cout<<"jestem w moim przed pętlą"<<std::endl;
        //     start = std::chrono::steady_clock::now();
        //     for(auto s : randomStart)
        //     {
        //         // std::cout << "Working on source: " << s << std::endl;
        //         randomStart.pop_back();
        //         algorithm->findPath(graph, s);
        //     }
        //     end = std::chrono::steady_clock::now();

        //     double t = (double) std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() / (double)size;
        //     resultsFile << "p res sp ss dijkstra\n";
        //     resultsFile << "f " << argv[3] << " " << argv[5] << '\n';
        //     resultsFile << "g " << graph.getVertexSize() << " " << graph.getEdgesSize() << " " << graph.getMinCost() << " " << graph.getMaxCost() << "\n";
        //     resultsFile << "t " << t / 1000;
        //     std::cout << std::endl << t << std::endl;
        // }
        // else{
        //     if(strcmp(argv[4],"-ss") == 0)
        //     {
        //         short mode = 4;
        //         auto sourceList = parser.readStartPoint();
        //         if(strcmp(argv[1], "dijkstra") == 0)
        //         {
        //             mode = 0;
        //         }
        //         else if(strcmp(argv[1], "dial") == 0)
        //         {
        //             algorithm = std::make_unique<Dial>();
        //             mode = 1;
        //         }
        //         else if(strcmp(argv[1], "radixheap") == 0)
        //         {
        //             algorithm = std::make_unique<RadixHeapAlgorithm>();
        //         }

        //         auto start = std::chrono::steady_clock::now();
        //         size_t listSize = sourceList.size();
        //         for(auto s : sourceList)
        //         {
        //             sourceList.pop_back();
        //             auto distance = algorithm->findPath(graph, s);
        //         }
        //         auto end = std::chrono::steady_clock::now();

        //         std::cout<<(double) std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<<std::endl;
        //         std::cout<<(double)listSize<<std::endl;

        //         double t = (double) std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() / (double)listSize;
        //         resultsFile << "p res sp ss dijkstra\n";
        //         resultsFile << "f " << argv[3] << " " << argv[5] << '\n';
        //         resultsFile << "g " << graph.getVertexSize() << " " << graph.getEdgesSize() << " " << graph.getMinCost() << " " << graph.getMaxCost() << "\n";
        //         resultsFile << "t " << t / 1000;
        //         std::cout << std::endl << t << std::endl;
        //     }
        //     else
        //     {
        //         short mode;
        //         auto pairs = parser.readP2P();
        //         if(strcmp(argv[1], "dijkstra") == 0)
        //         {
        //             mode = 0;
        //         }
        //         else if(strcmp(argv[1], "dial") == 0)
        //         {
        //             algorithm = std::make_unique<Dial>();
        //             mode = 1;
        //         }
        //         else if(strcmp(argv[1], "radixheap") == 0)
        //         {
        //             algorithm = std::make_unique<RadixHeapAlgorithm>();
        //         }
        //         resultsFile << "f " << argv[3] << " " << argv[5] << '\n';
        //         resultsFile << "g " << graph.getVertexSize() << " " << graph.getEdgesSize() << " " << graph.getMinCost() << " " << graph.getMaxCost() << "\n";
        //         while(!pairs.empty())
        //         {
        //             std::cout << "Pairs left:" << pairs.size() << std::endl;
        //             size_t s = pairs.back().first;
        //             size_t f = pairs.back().second;
        //             pairs.pop_back();
        //             auto d = algorithm->findPath(graph, s, f);
        //             resultsFile << "d " << s << " " << f << " " << d[0] << '\n';
        //         }
        //     }
        // }
        // graph.~Graph();
        // parser.~Parser();


    // }


    

    
            
    return 0;
}

std::vector<int> findRandom(int vertexSize){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, vertexSize);
    std::vector<int> randomNumber;

    for(auto i = 0; i < 5; i++){
        randomNumber.push_back(dist(gen));
    }
    return randomNumber;
}

std::vector<std::pair<int, int>> findRandomPairs(int vertexSize){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, vertexSize);
    std::vector<std::pair<int, int>> randomPairs;

    while(randomPairs.size() != 5){
        auto first = dist(gen);
        auto second = dist(gen);
        if(first != second) randomPairs.push_back(std::make_pair(first, second));
    }

    return randomPairs;
}










