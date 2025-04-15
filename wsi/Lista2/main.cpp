#include <iostream>

#include "Game.hpp"

int main()
{
    // Game game();
    int64_t gameBoard = 0x123456789ABCDFE0;
    Board board(gameBoard, 4);
    if (board.validate())
    {
        std::cout << "Valid" << std::endl;
    }
    else
    {
        std::cout << "Not Valid" << std::endl;
    }

    return 0;
}