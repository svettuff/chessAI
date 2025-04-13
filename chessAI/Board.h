#pragma once
#include <vector>

#include "Piece.h"

// board data

class Board
{
public:
    void Draw(const std::vector<Piece*> pieces);
    
    // set piece

private:
    std::string board[8][8];
};
