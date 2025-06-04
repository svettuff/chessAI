#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(int r, int c, int i);

    std::vector<std::pair<int, int>> GetPossibleMoves() override;
};
