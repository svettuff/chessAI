#include "Game.h"

#include <iostream>
#include <string>

#include "Pawn.h"

Game::Game()
{
    GeneratePieces();
}

Game::~Game()
{
    DeletePieces();
}

void Game::Play()
{
    while (true)
    {
        board.Draw(pieces);
        std::string move;
        std::cin >> move;
    }
}

void Game::GeneratePieces()
{
    pieces.emplace_back(new Pawn(5, 0, 0));
    pieces.emplace_back(new Pawn(5, 2, 1));
}

void Game::DeletePieces()
{
    for (auto *piece : pieces)
        delete piece;
}
