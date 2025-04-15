#pragma once

#include <cstdint>

class Board
{
public:
    Board(unsigned int); // random board
    Board(int64_t, unsigned int); // board with given state
    
    bool validate() const;
    void setBoard(int64_t);
    int64_t getBoard() const;

    void createValidBoard();
    // void printBoard() const;

private:
    unsigned int coutInversion() const;

    int64_t board_;
    unsigned int size_; 
};