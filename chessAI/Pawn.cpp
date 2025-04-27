#include "Pawn.h"

Pawn::Pawn(int r, int c, int i) : Piece(r, c, i)
{
    sign = u8"\u2659"; // TODO: need to be black on white background
}

std::vector<std::pair<int, int>> Pawn::GetPossibleMoves()
{
    std::vector<std::pair<int, int>> moves;

    if (index < 16)
        direction = Direction::Up;
    else if (index < 32)
        direction = Direction::Down;
    
    moves.emplace_back(row + static_cast<int>(direction), col);

    if ((direction == Direction::Up && row == 1) || (direction == Direction::Down && row == 6))
        moves.emplace_back(col + 2 * static_cast<int>(direction), col);

    return moves;
}
