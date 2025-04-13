#include "Game.h"

#include <iostream>
#include <string>

#include "Pawn.h"

void Game::Play()
{
    
    while (true)
    {
        board.Draw();
        std::string move;
        std::cin >> move;
    }
}

void Game::GeneratePieces()
{
    pieces.emplace_back(new Pawn(5, 0, 0));
    pieces.emplace_back(new Pawn(5, 1, 1));
}

void Game::DeletePieces()
{
    for (auto *piece : pieces)
        delete piece;
}
