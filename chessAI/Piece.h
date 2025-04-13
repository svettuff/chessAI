#pragma once
#include "Move.h"
#include <string>
#include <vector>

// figure and inheritors(pawn, king)

class Piece
{
public:
    Piece(int r, int c, int i, int color) : row(r), col(c), index(i), color(color) {}
    Piece(){}

    std::string GetSign() const { return sign; }

    virtual std::vector<Move> GetRule(int row, int col, int id, int color) = 0;

    virtual std::vector<Piece> startPosition(int index);

    virtual ~Piece() {}
    
protected:
    int row = 0;
    int col = 0;
    int index = 0;
    int color = 0;
    std::string sign;
};

