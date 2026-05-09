#include "../include/PawnBuilder.hpp"

#include "../include/ChessPiece.hpp"

std::unique_ptr<ChessPiece> PawnBuilder::create()
{
    auto chessPiece = std::make_unique<ChessPiece>();
    setChessPieceName(*chessPiece, ChessPieceName::Pawn);
    setChessPieceVision(*chessPiece, ChessPieceVision::Front);
    setChessPieceNotation(*chessPiece, ' ');

    return chessPiece;
}