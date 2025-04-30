#include <iostream>

#include <vector>

#include <memory>
#include "IHeuristics.hpp"
#include "ManhatanDistance.hpp"
#include "LinearConflicts.hpp"
#include "Game.hpp"

int main()
{
    std::vector<std::shared_ptr<IHeuristics>> heuristics;
    unsigned int size = 4;
    heuristics.push_back(std::make_shared<ManhatanDistance>(size));
    heuristics.push_back(std::make_shared<LinearConflicts>(size));
    Game game(heuristics, size);

    int64_t finalState;
    if (size == 3)
    {
        finalState = 0x123456780;
    }
    else
    {
        finalState = 0x123456789ABCDEF0;
    }

    auto initialState = game.createValidBoard();
    // int64_t initialState = 0xe867fb45d12a3c90;
    std::cout <<std::hex << initialState << std::endl;
    auto path = game.findShortestPath(initialState, finalState);
    // auto path2 = game.findShortestPath2(initialState, finalState);

    std::cout << std::dec << "Path size: " << path.size() << std::endl;
    // std::cout << std::dec << "Path size2: " << path2.size() << std::endl;    

    return 0;
}