#include "Pawn.h"

Pawn::Pawn(int r, int c, int i) : Piece(r, c, i)
{
    sign = "♙";
}

void Pawn::GetRule()
{
    // return vector of coordinates
    // std::pair<int, int> pair;
    //pair.first = 3;
    //pair.second = 4;
    // std::vector<std::pair<int, int>> array;

    std::vector<std::pair<int, int>> moves;

    if (index < 16)
        direction = -1;
    else if (index < 32)
        direction = 1;
    
    moves.emplace_back(row + direction, col);

    if ((direction == -1 && row == 1) || (direction == 1 && row == 6))
        moves.emplace_back(col + 2 * direction, col);
}
