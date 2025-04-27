#pragma once
#include "Board.h"

// game logic

class Game
{
public:
    Game();
    ~Game();
    void Play();

private:
    void GeneratePieces();
    void DeletePieces();
    void ProccessMove(const std::string& move);
    
    Board board;
    std::vector<Piece*> pieces;
};
