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
    
    const std::vector<std::pair<int, int>> directions = {
        {-1, 0}, {1, 0},   
        {0, -1}, {0, 1},  
        {-1, -1}, {-1, 1},
        {1, -1}, {1, 1}    
    };

    for (const auto& dir : directions)
    {
        for (int step = 1; step < 8; ++step)
        {
            int newRow = row + dir.first * step;
            int newCol = col + dir.second * step;
            
            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
                moves.emplace_back(newRow, newCol);
            else
                break; 
        }
    }

    return moves;
}