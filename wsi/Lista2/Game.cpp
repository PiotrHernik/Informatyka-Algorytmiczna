#include "Game.hpp"

Game::Game(std::vector<IHeuristics> heuristics, unsigned int size) : heuristics_(heuristics), board_(Board(size)){}

Game::Game(int64_t board, std::vector<IHeuristics> heuristics, unsigned int size) : heuristics_(heuristics), board_(Board(board, size)){}

