#pragma once
#include <memory>

#include "Board.h"

// game logic

class Game
{
public:
    Game();
    void Play();

private:
    void GeneratePieces();
    void ProcessMove(const std::string& move);
    
    Board board;
    std::vector<std::unique_ptr<Piece>> pieces;
};
