#pragma once
#include <string>

// figure and inheritors(pawn, king)

class Piece
{
public:
    virtual ~Piece() = default;
    virtual std::string GetRule() = 0;

    std::string GetSign() const { return sign; }

protected:
    std::string sign;
};

