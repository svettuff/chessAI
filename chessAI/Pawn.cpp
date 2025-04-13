#include "Pawn.h"
#include <vector>

Pawn::Pawn()
{
    sign = "♙";
}

std::vector<Piece> Pawn::startPosition( int startIndex)
{
    std::vector<Piece> pieces;
    
    bool isWhite = startIndex >= 16;
    int row = isWhite ? 6 : 1;
    int baseIndex = isWhite ? 17 : 1;
    
    for (int col = 0; col < 8; col++) {
        pieces.emplace_back(row, col, baseIndex + col, color);
    }
    return pieces;
}

std::vector<Move> Pawn::GetRule(int currentRow, int currentCol, int id, int pieceColor)
{
    std::vector<Move> moves;
    int direction = (pieceColor == 0) ? 1 : -1;
    
    if ((pieceColor == 1 && currentRow == 6) || (pieceColor == 0 && currentRow == 1))
        moves.emplace_back(currentRow + 2 * direction, currentCol, id, pieceColor);
    else 
        moves.emplace_back(currentRow + 1 * direction, currentCol, id, pieceColor);
    
    return moves;
}