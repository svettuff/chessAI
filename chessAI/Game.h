#pragma once
#include "Board.h"

// game logic

class Game
{
public:
    void Play();

private:
    void GeneratePieces();
    void DeletePieces();
    
    Board board;
    std::vector<Piece*> pieces;
};
