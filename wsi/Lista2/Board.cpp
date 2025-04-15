#include "Board.hpp"

#include <vector>

Board::Board(unsigned int size = 3) : size_(size)
{
    createValidBoard();
}

Board::Board(int64_t board, unsigned int size) : board_(board), size_(size)
{
}

void Board::setBoard(int64_t board)
{
    board_ = board;
}

int64_t Board::getBoard() const
{
    return board_;
}

unsigned int Board::coutInversion() const
{
    std::vector<int> tiles(16);

    // Rozbijanie int64 na 16 wartości 4-bitowych
    for (auto i = 0; i < 16; ++i) {
        tiles[15 - i] = (board_ >> (i * 4)) & 0xF;
    }

    // Liczenie inwersji
    unsigned int inversions = 0;
    for (auto i = 0; i < 16; ++i) {
        if (tiles[i] == 0) continue; // pomijamy puste pole

        for (auto j = i + 1; j < 16; ++j) {
            if (tiles[j] == 0) continue;

            if (tiles[i] > tiles[j]) {
                ++inversions;
            }
        }
    }

    return inversions;
}

bool Board::validate() const
{
    bool isEven = size_ % 2 == 0 ? true : false;
    
    auto numberOfInversion = coutInversion();

    if (isEven)
    {
        if (numberOfInversion % 2 == 0) 
        {
            return true;
        } 
    }
    else
    {
        if (numberOfInversion % 2 == 0) 
        {
            return true;
        }
    }
    return false;
}

void Board::createValidBoard()
{
    board_ = 0x123456789ABCDEF0;
}



