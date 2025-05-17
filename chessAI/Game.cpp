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
        ProccessMove(move);
    }
}

void Game::GeneratePieces()
{
    pieces.emplace_back(new Pawn(6, 0, 0));
    pieces.emplace_back(new Pawn(6, 1, 1));
}

void Game::DeletePieces()
{
    for (auto *piece : pieces)
        delete piece;
}

void Game::ProccessMove(const std::string& move) // TODO: check is correct format, REFACTOR!!!!
{
    std::string position = move.substr(0, 2);  
    std::string destination = move.substr(2);

    // r, c
    std::pair<int, int> piece_position;
    piece_position.first = position[0] - '0';
    piece_position.first = 8 - piece_position.first;
    piece_position.second = position[1] - 'A';
    
    std::pair<int, int> piece_destination;
    piece_destination.first = destination[0] - '0';
    piece_destination.first = 8 - piece_destination.first;
    piece_destination.second = destination[1] - 'A';

    for (auto piece : pieces)
    {
        if (piece->GetRow() == piece_position.first && piece->GetCol() == piece_position.second)
        {
            auto possibleMoves = piece->GetPossibleMoves(); 
            for (auto& possibleMove : possibleMoves)
            {
                if (possibleMove == piece_destination)
                {
                    piece->SetRow(piece_destination.first);
                    piece->SetCol(piece_destination.second);
                }
            }
        }
    }
}
