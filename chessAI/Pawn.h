#pragma once
#include "Piece.h"

class Pawn : public Piece
{

public:
    Pawn();
    
    std::vector<Piece> startPosition(int index) override;
    
    std::vector<Move> GetRule(int row, int col, int id, int color) override;
};

