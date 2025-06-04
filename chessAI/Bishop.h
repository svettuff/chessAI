#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(int r, int c, int i);

    std::vector<std::pair<int, int>> GetPossibleMoves() override;
};
