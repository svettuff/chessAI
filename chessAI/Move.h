#pragma once

class Move {
public:
    int row;
    int col;
    int index;
    int color;

    Move(int r, int c, int i, int color) : row(r), col(c), index(i), color(color) {}
};
