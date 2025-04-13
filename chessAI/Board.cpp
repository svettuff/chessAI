#include "Board.h"

#include <iostream>

void Board::Draw()
{
    const int size = 8;
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if ((row + col) % 2 == 0)
                std::cout << "\033[47m  \033[0m";
            else
               std::cout << "\033[40m  \033[0m";
        }
        std::cout << std::endl;
    }
}

void Board::Initialize()
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            
        }
    }
}
