#include "King.h"

King::King(int r, int c, int i) : Piece(r, c, i)
{
    if (index < 16)
        sign = u8"\u2654";
    else 
        sign = u8"\u265A";
}

std::vector<std::pair<int, int>> King::GetPossibleMoves()
{
    std::vector<std::pair<int, int>> moves;
    
    for (int r = -1; r <= 1; r++)
    {
        for (int c = -1; c <= 1; c++)
        {
            if (r == 0 && c == 0) continue;

            int availableRowMove = row + r;
            int availableColMove = col + c;
            
            if (availableRowMove >= 0 && availableRowMove < 8 && availableColMove >= 0 && availableColMove < 8)
                moves.emplace_back(availableRowMove, availableColMove);
        }
    }
    return moves;
}

