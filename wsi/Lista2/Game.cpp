#include <vector>

#include "Game.hpp"
#include <random>
#include <bits/algorithmfwd.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

Game::Game(std::vector<std::shared_ptr<IHeuristics>> heuristics, unsigned int size) : heuristics_(heuristics), size_(size)
{
    board_ = createValidBoard();

    if (size_ == 3)
    {
        finalState_ = 0x12345678;
    }
    else
    {
        finalState_ = 0x123456789ABCDEF0;
    }
}

Game::Game(int64_t board, std::vector<std::shared_ptr<IHeuristics>> heuristics, unsigned int size) : heuristics_(heuristics), board_(board), size_(size){}

void Game::setBoard(int64_t board)
{
    board_ = board;
}

int64_t Game::getBoard() const
{
    return board_;
}


// function countInversion which counts the number of inversions in the board and remember about size_
unsigned int Game::countInversion(int64_t board) const {
    std::vector<int> tiles(size_ * size_);

    for (auto i = 0; i < size_ * size_; ++i) {
        tiles[size_ * size_ - 1 - i] = (board >> (i * 4)) & 0xF;
    }

    unsigned int inversions = 0;
    for (auto i = 0; i < size_ * size_; ++i) {
        if (tiles[i] == 0) continue;

        for (auto j = i + 1; j < size_ * size_; ++j) {
            if (tiles[j] == 0) continue;

            if (tiles[i] > tiles[j]) {
                ++inversions;
            }
        }
    }

    return inversions;
}

bool Game::validate(int64_t board) const {
    auto inversions = countInversion(board);

    std::vector<int> tiles(size_ * size_);
    for (auto i = 0; i < size_ * size_; ++i) {
        tiles[size_ * size_ - 1 - i] = (board >> (i * 4)) & 0xF;
    }

    int zero_pos = std::find(tiles.begin(), tiles.end(), 0) - tiles.begin();
    int zero_row_from_bottom = size_ - (zero_pos / size_);

    if (size_ % 2 == 1) {
        return inversions % 2 == 0;
    } else {
        return (inversions + zero_row_from_bottom) % 2 == 1;
    }
}

// create valid board with size_ * size_. It should be random and valid
// 0 should be at the end of the board
int64_t Game::createValidBoard() {
    std::vector<int> tiles(size_ * size_);
    std::random_device rd;
    std::mt19937 g(rd());
    int64_t board = 0;

    do {
        // Wypełnij wartościami 0 .. N-1
        for (int i = 0; i < size_ * size_; ++i) {
            tiles[i] = i;
        }

        std::shuffle(tiles.begin(), tiles.end(), g);

        // Sprawdź, czy ostatni element to 0 – jeśli nie, zamień
        auto zeroIt = std::find(tiles.begin(), tiles.end(), 0);
        std::iter_swap(zeroIt, tiles.begin());

        // Zbuduj board_
        board = 0;
        for (int i = 0; i < size_ * size_; ++i) {
            board |= (static_cast<int64_t>(tiles[i]) << (i * 4));
        }


    } while (!validate(board));
    return board;
}


void Game::print() const
{
    std::vector<int> tiles(size_ * size_);

    // Odczytaj od MSB do LSB
    for (int i = 0; i < size_ * size_; ++i) {
        // pole i (0–15) to bits (60–0) co 4 bity
        tiles[i] = (board_ >> ((size_ * size_ - 1 - i) * 4)) & 0xF;
    }

    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            std::cout << std::setw(2) << tiles[i * size_ + j] << " ";
        }
        std::cout << std::endl;
    }
    std::bitset<64> bits(board_);
    std::cout << bits << std::endl;
}

int Game::getHeuristicValue(int64_t actualState, int64_t finalState) const
{
    int heuristicValue = 0;
    for (const auto& heuristic : heuristics_)
    {
        heuristicValue += heuristic->getHeuristicValue(actualState, finalState);
    }
    return heuristicValue;
}

std::vector<int64_t> Game::findShortestPath2(int64_t start, int64_t end) const
{
    std::vector<int64_t> path;
    if (start == end)
        return {start};

    // size_t visitedCountF = 0, visitedCountB = 0;

    std::unordered_set<int64_t> visitedF, visitedB;
    std::unordered_map<int64_t, int64_t> parentF, parentB;

    auto cmp = [](const BoardState& a, const BoardState& b) {
        return (a.gcost + a.hcost) > (b.gcost + b.hcost);
    };

    std::priority_queue<BoardState, std::vector<BoardState>, decltype(cmp)> queueF(cmp);
    std::priority_queue<BoardState, std::vector<BoardState>, decltype(cmp)> queueB(cmp);

    queueF.push({start, 0, getHeuristicValue(start, end)});
    queueB.push({end, 0, getHeuristicValue(end, start)});
    parentF[start] = -1;
    parentB[end] = -1;

    int64_t meetingPoint = -1;

    auto expand = [&](auto& queue, auto& visited, auto& parent, auto& otherVisited, bool forward) -> int64_t {
        if (queue.empty()) return -1;

        BoardState current = queue.top();
        while ( visited.count(current.boardState) || otherVisited.count(current.boardState) )
        {
            queue.pop();
            if (queue.empty()) return -1;
            current = queue.top();
        }
        queue.pop();

        visited.insert(current.boardState);
        parent[current.boardState] = current.parent;

        if (forward)
            ++visitedCountF;
        else
            ++visitedCountB;

        if ((forward ? visitedCountF : visitedCountB) % 1000000 == 0)
        {
            std::cout << (forward ? "[F] " : "[B] ")
                      << "Visited states: " << (forward ? visitedCountF : visitedCountB) << std::endl;
        }

        for (int64_t next : generateNeighbors(current.boardState)) {
            // if (parent.count(next))
            //     continue;

            if (visited.count(next))
                continue;

            if (otherVisited.count(next)) {
                parent[next] = current.boardState;
                return next;  // Spotkanie!
            }

            int g = current.gcost + 1;
            int h = forward ? getHeuristicValue(next, end) : getHeuristicValue(next, start);

            queue.push(BoardState(next, g, h, current.boardState));
        }

        return -1;
    };

    while (!queueF.empty() && !queueB.empty())
    {
        // Porównaj F-costy z obu stron i rozwijaj "lepszą"
        int fFront = queueF.top().gcost + queueF.top().hcost;
        int fBack = queueB.top().gcost + queueB.top().hcost;

        if (fFront <= fBack)
        {
            meetingPoint = expand(queueF, visitedF, parentF, visitedB, true);
        }
        else
        {
            meetingPoint = expand(queueB, visitedB, parentB, visitedF, false);
        }

        if (meetingPoint != -1)
            break;
    }

    if (meetingPoint == -1)
    {
        std::cerr << "No path found from start to end." << std::endl;
        return path;
    }

    // Odtwarzanie ścieżki z przodu
    std::vector<int64_t> forwardPath;
    int64_t cur = meetingPoint;
    while (cur != -1)
    {
        forwardPath.push_back(cur);
        cur = parentF[cur];
    }
    std::reverse(forwardPath.begin(), forwardPath.end());

    // Odtwarzanie ścieżki z tyłu
    std::vector<int64_t> backwardPath;
    cur = parentB[meetingPoint];
    while (cur != -1)
    {
        backwardPath.push_back(cur);
        cur = parentB[cur];
    }

    // Łączenie ścieżek
    path = forwardPath;
    path.insert(path.end(), backwardPath.begin(), backwardPath.end());

    return path;
}

std::vector<int64_t> Game::findShortestPath(int64_t start, int64_t end) const
{
    visitedCount = 0;
    std::vector<int64_t> path;
    std::unordered_set<int64_t> visited;
    std::priority_queue<BoardState, std::vector<BoardState>, CompareBoardState> queue;
    std::unordered_map<int64_t, int64_t> parentMap;

    int h = getHeuristicValue(start, end);
    queue.push({start, 0, h});
    parentMap[start] = -1;

    while (!queue.empty())
    {
        BoardState current = queue.top();
        queue.pop();

        // std::cout << "Current: " << std::hex << current.boardState << std::endl;
        // std::cout << "Current heuristic value: " << std::dec << (current.gcost + current.hcost) << std::endl;

        if (current.boardState == end)
        {
            parentMap[end] = current.parent;
            break;

        }

        visited.insert(current.boardState);
        parentMap[current.boardState] = current.parent;
        visitedCount++;

        for (int64_t next : generateNeighbors(current.boardState))
        {
            if (visited.count(next))
            {
                // std::cout << "Already visited or in queue: " << std::hex << next << std::endl;
                continue;
            }
            // std::cout << "Next: " << std::hex << next << std::endl;

            int g = current.gcost + 1;
            int h = getHeuristicValue(next, end);
            
            // std::cout << std::dec << "Heuristic value: " << (g + h) << std::endl;

            queue.push({next, g, h, current.boardState});
        }
    }

    // Jeśli nie znaleziono ścieżki
    if (parentMap.find(end) == parentMap.end())
    {
        std::cerr << "No path found from start to end." << std::endl;
        return path;
    }

    // Odtwarzanie ścieżki
    int64_t current = end;
    while (current != -1)
    {
        path.push_back(current);
        current = parentMap[current];
    }
    std::reverse(path.begin(), path.end());

    return path;
}

std::vector<int64_t> Game::generateNeighbors(int64_t state) const {
    std::vector<int64_t> neighbors;
    int totalTiles = size_ * size_;

    // Znajdź pozycję pustego pola (wartość == 0)
    int emptyIndex = -1;
    for (int i = 0; i < totalTiles; ++i) {
        int value = (state >> (i * 4)) & 0xF;
        if (value == 0) {
            emptyIndex = i;
            break;
        }
    }

    if (emptyIndex == -1) {
        return neighbors; // brak pustego pola?
    }

    // Funkcja pomocnicza — zamień miejscami dwa pola
    auto swapTiles = [](int64_t s, int a, int b) {
        int64_t maskA = 0xFLL << (a * 4);
        int64_t maskB = 0xFLL << (b * 4);
        int64_t tileA = (s >> (a * 4)) & 0xF;
        int64_t tileB = (s >> (b * 4)) & 0xF;

        s &= ~maskA; // wyczyść pola
        s &= ~maskB;

        s |= tileA << (b * 4);
        s |= tileB << (a * 4);

        return s;
    };

    // Współrzędne pustego pola
    int row = emptyIndex / size_;
    int col = emptyIndex % size_;

    // Ruchy: góra, dół, lewo, prawo
    const int dRow[] = {-1, 1, 0, 0};
    const int dCol[] = {0, 0, -1, 1};

    for (int dir = 0; dir < 4; ++dir) {
        int newRow = row + dRow[dir];
        int newCol = col + dCol[dir];

        if (newRow >= 0 && newRow < size_ && newCol >= 0 && newCol < size_) {
            int neighborIndex = newRow * size_ + newCol;
            int64_t newState = swapTiles(state, emptyIndex, neighborIndex);
            neighbors.push_back(newState);
        }
    }

    return neighbors;
}

int Game::getSize(){
    return size_;
}


