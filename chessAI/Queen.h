#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(int r, int c, int i);

    std::vector<std::pair<int, int>> GetPossibleMoves() override;
};

