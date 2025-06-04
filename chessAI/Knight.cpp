#include "Knight.h"

Knight::Knight(int r, int c, int i) : Piece(r, c, i)
{
    if (index < 16)
        sign = u8"\u2658";  
    else
        sign = u8"\u265E";  
}

std::vector<std::pair<int, int>> Knight::GetPossibleMoves()
{
    std::vector<std::pair<int, int>> moves;
    
    const std::vector<std::pair<int, int>> jumps = {
        {-2, -1}, {-2, 1},
        {-1, -2}, {-1, 2},
        {1, -2},  {1, 2},
        {2, -1},  {2, 1}
    };

    for (const auto& jump : jumps)
    {
        int newRow = row + jump.first;
        int newCol = col + jump.second;
        
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
            moves.emplace_back(newRow, newCol);
    }

    return moves;
}