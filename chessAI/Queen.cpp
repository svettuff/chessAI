#include "Queen.h"

Queen::Queen(int r, int c, int i) : Piece(r, c, i)
{
    if (index < 16)
        sign = u8"\u2655"; // White Queen
    else 
        sign = u8"\u265B"; // Black Queen
}

std::vector<std::pair<int, int>> Queen::GetPossibleMoves()
{
    std::vector<std::pair<int, int>> moves;



    return moves;
}