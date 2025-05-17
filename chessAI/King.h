#pragma once
#include "Piece.h"

class King : public Piece
{
public:
    King(int r, int c, int i);

    std::vector<std::pair<int, int>> GetPossibleMoves() override;
};
