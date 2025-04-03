#include "Game.h"

#include <iostream>
#include <string>

void Game::Play()
{
    while (true)
    {
        board.Draw();
        std::string move;
        std::cin >> move;
    }
}
