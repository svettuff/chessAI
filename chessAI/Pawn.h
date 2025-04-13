#pragma once
#include "Piece.h"

class Pawn : public Piece
{

public:
    Pawn(int r, int c, int i);
    
    void GetRule() override;
};

