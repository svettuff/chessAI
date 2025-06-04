#include "Bishop.h"

Bishop::Bishop(int r, int c, int i) : Piece(r, c, i)
{
    if (index < 16)
        sign = u8"\u2657"; 
    else
        sign = u8"\u265D";  
}

std::vector<std::pair<int, int>> Bishop::GetPossibleMoves()
{
    std::vector<std::pair<int, int>> moves;
    
    int directions[4][2] = {
        {-1, -1}, 
        {-1,  1}, 
        { 1, -1}, 
        { 1,  1}  
    };

    for (auto& dir : directions)
    {
        int dr = dir[0];
        int dc = dir[1];

        int newRow = row + dr;
        int newCol = col + dc;

        while (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
        {
            moves.emplace_back(newRow, newCol);
            newRow += dr;
            newCol += dc;
        }
    }
    return moves;
}