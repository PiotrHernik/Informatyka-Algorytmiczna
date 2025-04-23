#include <iostream>

#include <vector>

#include <memory>
#include "IHeuristics.hpp"
#include "ManhatanDistance.hpp"
#include "Game.hpp"

int main()
{
    std::vector<std::shared_ptr<IHeuristics>> heuristics;
    unsigned int size = 4;
    heuristics.push_back(std::make_shared<ManhatanDistance>(size));
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
    std::cout <<std::hex << initialState << std::endl;
    auto path = game.findShortestPath(initialState, finalState);
    auto path2 = game.findShortestPath2(initialState, finalState);

    std::cout << std::dec << "Path size: " << path.size() << std::endl;
    std::cout << std::dec << "Path size2: " << path2.size() << std::endl;
    // game.print();
    // std::cout << game.countInversion() <<std::endl;
    // std::cout << game.getHeuristicValue(0x843215760, 0x123456780) << std::endl;
    // auto path = game.findShortestPath(0x8F932AEDC045B176, 0x123456789ABCDEF0);
    // std::cout << "Path size: " << std::dec << path.size() << std::endl;

// print stats like a board i row and column, every state in path
    // for (const auto& state : path)
    // {
    //     std::cout << std::hex << state << std::endl;
    //     game.setBoard(state);
    //     game.print();
    //     std::cout << "-------------------------" << std::endl;
    // }
    

    return 0;
}