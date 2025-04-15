#pragma once

#include <vector>

#include "IHeuristics.hpp"
#include "Board.hpp"

class Game
{
public:
    Game(std::vector<IHeuristics>, unsigned int);
    Game(int64_t, std::vector<IHeuristics>, unsigned int);

    

private:
    Board board_;
    std::vector<IHeuristics> heuristics_;
};