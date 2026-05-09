#include "../include/RookBuilder.hpp"

std::unique_ptr<ChessPiece> RookBuilder::create()
{
    auto chessPiece = std::make_unique<ChessPiece>();

    setChessPieceName(*chessPiece, ChessPieceName::Rook);
    setChessPieceVision(*chessPiece, ChessPieceVision::Straight);
    setChessPieceNotation(*chessPiece, 'R');

    return chessPiece;
}