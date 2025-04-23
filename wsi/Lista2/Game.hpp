#pragma once

#include <vector>
#include <memory>

#include "IHeuristics.hpp"

struct BoardState
{
    BoardState(int64_t state, int gcost, int hcost, int64_t parent = -1)
        : boardState(state), gcost(gcost), hcost(hcost), parent(parent){}
    int64_t boardState;
    int gcost;
    int hcost;
    int64_t parent;
};


struct CompareBoardState
{
    bool operator()(const BoardState& a, const BoardState& b)
    {
        return a.gcost + a.hcost > b.gcost + b.hcost;
    }
};

class Game
{
public:
    Game(std::vector<std::shared_ptr<IHeuristics>>, unsigned int);
    Game(int64_t, std::vector<std::shared_ptr<IHeuristics>>, unsigned int);

    bool validate(int64_t) const;
    void setBoard(int64_t);
    int64_t getBoard() const;

    int64_t createValidBoard();

    void print() const;

    int getHeuristicValue(int64_t, int64_t) const;
    unsigned int countInversion(int64_t board) const;

    std::vector<int64_t> findShortestPath(int64_t, int64_t) const;
    std::vector<int64_t> findShortestPath2(int64_t start, int64_t end) const;
    mutable size_t visitedCountF = 0;
    mutable size_t visitedCountB = 0;
    mutable size_t visitedCount = 0;
    int getSize();

private:
    std::vector<int64_t> generateNeighbors(int64_t) const;

    std::vector<std::shared_ptr<IHeuristics>> heuristics_;
    int64_t board_;
    unsigned int size_;
    int64_t finalState_;
    // int64_t actualState_;
};