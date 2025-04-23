#include "ManhatanDistance.hpp"

#include <iostream>

ManhatanDistance::ManhatanDistance(unsigned int size) : size_(size)
{
    if (size_ < 2 || size_ > 4)
    {
        std::cerr << "Invalid size for ManhatanDistance. Size must be between 2 and 4." << std::endl;
        exit(EXIT_FAILURE);
    }
}

int ManhatanDistance::getHeuristicValue(int64_t currentState, int64_t finalState) const
{
    int distance = 0;
    for (int i = 0; i < size_ * size_; ++i)
    {
        int tile = (currentState >> (i * 4)) & 0xF;
        if (tile == 0) continue;

        int finalPos = (finalState >> (tile * 4)) & 0xF;
        int x1 = i / size_;
        int y1 = i % size_;
        int x2 = finalPos / size_;
        int y2 = finalPos % size_;

        distance += abs(x1 - x2) + abs(y1 - y2);
    }
    return distance;
}

void ManhatanDistance::setSize(unsigned int size)
{
    if (size < 2 || size > 4)
    {
        std::cerr << "Invalid size for ManhatanDistance. Size must be between 2 and 4." << std::endl;
        exit(EXIT_FAILURE);
    }
    size_ = size;
}  