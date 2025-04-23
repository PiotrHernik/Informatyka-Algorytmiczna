#include <iostream>

#include <vector>

#include <memory>
#include <climits>

#include "IHeuristics.hpp"
#include "ManhatanDistance.hpp"
#include "LinearConflicts.hpp"
#include "Game.hpp"

int main()
{
    std::vector<std::shared_ptr<IHeuristics>> heuristics;
    std::vector<std::shared_ptr<IHeuristics>> heuristics2;
    unsigned int size = 4;
    heuristics.push_back(std::make_shared<ManhatanDistance>(size));
    heuristics.push_back(std::make_shared<LinearConflicts>(size));

    heuristics2.push_back(std::make_shared<ManhatanDistance>(size));
    int64_t finalState;
    if (size == 3)
    {
        finalState = 0x123456780;
    }
    else
    {
        finalState = 0x123456789ABCDEF0;
    }

    unsigned long avgPathSize = 0;
    unsigned long avgPathSize2 = 0;
    unsigned long long avgVisitedStates = 0;
    unsigned long long avgVisitedStates2 = 0;
    for(auto i = 0; i < 5; i++)
    {
    Game game(heuristics, size);
    Game game2(heuristics2, size);
        std::cout << "Przed createValidBoard" << std::endl;
        auto initialState = game.createValidBoard();
        std::cout <<std::hex << initialState << std::endl;
        auto path = game.findShortestPath(initialState, finalState);
        
        auto path2 = game2.findShortestPath(initialState, finalState);
        std::cout <<std::dec << "po findfath" << std::endl;
        avgPathSize += path.size();
        avgPathSize2 += path.size();
        // avgVisitedStates += game.visitedCount;
        if (ULLONG_MAX - avgVisitedStates >= game.visitedCount && ULLONG_MAX - avgVisitedStates2 >= game2.visitedCount)
        {
            avgVisitedStates += game.visitedCount;
            avgVisitedStates2 += game2.visitedCount;
        }
        else
        {
            std::cerr << "Przekroczenie zakresu! visitedCount zbyt duże.\n";
            // Możesz też przerwać, wyzerować, itp.
        }
        // if ( i % 10 == 0) 
        std::cout << "kolejna iteracja: " << i << std::endl;
    }

    avgPathSize /= 5;
    avgPathSize2 /= 5;
    avgVisitedStates /= 5;
    avgVisitedStates2 /= 5;
    // game.print();
    // std::cout << game.countInversion() <<std::endl;
    // std::cout << game.getHeuristicValue(0x843215760, 0x123456780) << std::endl;

    // std::cout << "Path size: " << std::dec << path.size() << std::endl;

// print stats like a board i row and column, every state in path
    // for (const auto& state : path)
    // {
    //     std::cout << std::hex << state << std::endl;
    //     game.setBoard(state);
    //     game.print();
    //     std::cout << "-------------------------" << std::endl;
    // }

    // std::cout <<std::dec << "Visited count F: " << game.visitedCountF << std::endl;
    // std::cout << "Visited count B: " << game.visitedCountB << std::endl;
    // std::cout << "Visited sum: " << game.visitedCountF + game.visitedCountB << std::endl;
    // std::cout << "Visited count: " << game.visitedCount << std::endl;

    std::cout << "avgPathSize: " <<avgPathSize <<std::endl;
    std::cout << "avgVisitedStates: " << avgVisitedStates << std::endl;
    std::cout << "avgPathSize2: " <<avgPathSize2 <<std::endl;
    std::cout << "avgVisitedStates2: " << avgVisitedStates2 << std::endl;
    

    return 0;
}