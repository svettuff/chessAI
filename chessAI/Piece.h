#pragma once
#include <string>
#include <vector>

// figure and inheritors(pawn, king)

class Piece
{
public:
    std::string GetSign() const { return sign; }

    virtual void GetRule() = 0;

    virtual ~Piece() = default;

    int GetRow() const { return row; }
    int GetCol() const { return col; }
    
protected:
    Piece(int r, int c, int i) : row(r), col(c), index(i) {}
    
    int row = 0;
    int col = 0;
    int index = 0;
    std::string sign;
    int direction = 0;
};

