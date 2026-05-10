#include "../include/RookBuilder.hpp"

std::unique_ptr<ChessPiece> RookBuilder::create(ChessPieceColor color)
{
    auto chessPiece = std::make_unique<ChessPiece>();

    setChessPieceName(*chessPiece, ChessPieceName::Rook);
    setChessPieceVision(*chessPiece, ChessPieceVision::Straight);
    setChessPieceNotation(*chessPiece, 'R');
    setChessPieceColor(*chessPiece, color);

    return chessPiece;
}