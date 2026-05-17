#include "../include/PawnBuilder.hpp"

#include "../include/ChessPiece.hpp"

std::unique_ptr<ChessPiece> PawnBuilder::create(ChessPieceColor color) const
{
    auto chessPiece = std::make_unique<ChessPiece>();
    setChessPieceName(*chessPiece, ChessPieceName::Pawn);
    setChessPieceVision(*chessPiece, ChessPieceVision::Front);
    setChessPieceNotation(*chessPiece, ' ');
    setChessPieceColor(*chessPiece, color);
    return chessPiece;
}