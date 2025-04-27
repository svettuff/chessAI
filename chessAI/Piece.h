#pragma once
#include <string>
#include <vector>

// figure and inheritors(pawn, king)

//TODO: Make all pieces

enum class Direction : int {
    Up   = -1,
    Down = 1
};

class Piece
{
public:
    virtual ~Piece() = default;
    
    virtual std::vector<std::pair<int, int>> GetPossibleMoves() = 0;

    int GetCol() const { return col; }
    int GetRow() const { return row; }
    std::string GetSign() const { return sign; }

    void SetCol(int col) { this->col = col; }
    void SetRow(int row) { this->row = row; }
    
protected:
    Piece(int r, int c, int i) : row(r), col(c), index(i) {}
    
    int col = 0;
    int index = 0;
    int row = 0;
    
    std::string sign;

    Direction direction;
};

