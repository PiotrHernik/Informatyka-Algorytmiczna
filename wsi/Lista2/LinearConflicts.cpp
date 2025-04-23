#include "LinearConflicts.hpp"
#include <vector>

LinearConflicts::LinearConflicts(unsigned int size) : size_(size)
{
}


int LinearConflicts::getHeuristicValue(int64_t currentState, int64_t finalState) const
{
    int linearConflicts = 0;

    // Wygeneruj docelowe pozycje kafelków
    std::vector<int> goalRow(size_ * size_);
    std::vector<int> goalCol(size_ * size_);

    for (int tile = 1; tile < size_ * size_; ++tile)
    {
        int pos = (finalState >> (tile * 4)) & 0xF;
        goalRow[tile] = pos / size_;
        goalCol[tile] = pos % size_;
    }

    // Sprawdź konflikty w wierszach
    for (int row = 0; row < size_; ++row)
    {
        for (int i = 0; i < size_; ++i)
        {
            int index1 = row * size_ + i;
            int tile1 = (currentState >> (index1 * 4)) & 0xF;
            if (tile1 == 0 || goalRow[tile1] != row) continue;

            for (int j = i + 1; j < size_; ++j)
            {
                int index2 = row * size_ + j;
                int tile2 = (currentState >> (index2 * 4)) & 0xF;
                if (tile2 == 0 || goalRow[tile2] != row) continue;

                if (goalCol[tile1] > goalCol[tile2])
                    linearConflicts++;
            }
        }
    }

    // Sprawdź konflikty w kolumnach
    for (int col = 0; col < size_; ++col)
    {
        for (int i = 0; i < size_; ++i)
        {
            int index1 = i * size_ + col;
            int tile1 = (currentState >> (index1 * 4)) & 0xF;
            if (tile1 == 0 || goalCol[tile1] != col) continue;

            for (int j = i + 1; j < size_; ++j)
            {
                int index2 = j * size_ + col;
                int tile2 = (currentState >> (index2 * 4)) & 0xF;
                if (tile2 == 0 || goalCol[tile2] != col) continue;

                if (goalRow[tile1] > goalRow[tile2])
                    linearConflicts++;
            }
        }
    }

    return linearConflicts;
}

void LinearConflicts::setSize(unsigned int)
{
}
