#include "Board.h"

#include <iostream>

void Board::Draw(const std::vector<std::unique_ptr<Piece>>& pieces)
{
    // Fill cells
    const int size = 8;
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if ((row + col) % 2 == 0)
                board[row][col] = "\033[47m  \033[0m";
            else
               board[row][col] = "\033[40m  \033[0m";
        }
    }

    // Fill pieces
    for (auto& piece : pieces)
    {
        int r = piece->GetRow();
        int c = piece->GetCol();
        std::string sign = piece->GetSign();

        bool lightSquare = ((r + c) % 2 == 0);
        std::string bgColor = lightSquare ? "\033[47m" : "\033[40m";
        std::string fgColor = lightSquare ? "\033[30m" : "\033[97m";

        board[r][c] = bgColor + fgColor + sign + " \033[0m";
    }

    // Drawing
    for (int row = 0; row < size; row++)
    { 
        for (int col = 0; col < size; col++)
            std::cout << board[row][col] << " ";
        
        std::cout << size - row;
        std::cout << std::endl;
    }

    std::cout << "";
    for (int col = 0; col < size; ++col)
        std::cout << static_cast<char>('A' + col) << "  ";
    std::cout << '\n';
}
