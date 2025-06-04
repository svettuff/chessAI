#include "Game.h"

#include <iostream>
#include <string>

#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "Rook.h"

Game::Game()
{
    GeneratePieces();
}

void Game::Play()
{
    while (true)
    {
        board.Draw(pieces);
        std::string move;
        std::cin >> move;
        ProcessMove(move);
    }
}

void Game::GeneratePieces()
{
    for (int col = 0; col < 8; ++col)
        pieces.emplace_back(std::make_unique<Pawn>(6, col, 8 + col)); 
    
    for (int col = 0; col < 8; ++col)
        pieces.emplace_back(std::make_unique<Pawn>(1, col, 48 + col));  
    
    pieces.emplace_back(std::make_unique<Rook>(7, 0, 0));
    pieces.emplace_back(std::make_unique<Knight>(7, 1, 1));
    pieces.emplace_back(std::make_unique<Bishop>(7, 2, 2));
    pieces.emplace_back(std::make_unique<Queen>(7, 3, 3));
    pieces.emplace_back(std::make_unique<King>(7, 4, 4));
    pieces.emplace_back(std::make_unique<Bishop>(7, 5, 5));
    pieces.emplace_back(std::make_unique<Knight>(7, 6, 6));
    pieces.emplace_back(std::make_unique<Rook>(7, 7, 7));
    
    pieces.emplace_back(std::make_unique<Rook>(0, 0, 56));
    pieces.emplace_back(std::make_unique<Knight>(0, 1, 57));
    pieces.emplace_back(std::make_unique<Bishop>(0, 2, 58));
    pieces.emplace_back(std::make_unique<Queen>(0, 3, 59));
    pieces.emplace_back(std::make_unique<King>(0, 4, 60));
    pieces.emplace_back(std::make_unique<Bishop>(0, 5, 61));
    pieces.emplace_back(std::make_unique<Knight>(0, 6, 62));
    pieces.emplace_back(std::make_unique<Rook>(0, 7, 63));
}

// TODO: check is correct format
// TODO: tell if move is incorrect
void Game::ProcessMove(const std::string& move)
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

    for (auto& piece : pieces)
    {
        if (piece->GetRow() == piece_position.first && piece->GetCol() == piece_position.second)
        {
            auto possibleMoves = piece->GetPossibleMoves(); 
            for (auto& possibleMove : possibleMoves)
            {
                if (possibleMove == piece_destination)
                {
                    // TODO: ignore for knight
                    auto* knight = dynamic_cast<Knight*>(piece.get());
                    if (knight == nullptr)
                    {
                        // TODO: check is there piece on the way
                    }
                        
                    piece->SetRow(piece_destination.first);
                    piece->SetCol(piece_destination.second);
                }
            }
        }
    }
}
