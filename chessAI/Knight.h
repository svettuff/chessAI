#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(int r, int c, int i);

    std::vector<std::pair<int, int>> GetPossibleMoves() override;

    int bebro = 10;
};
