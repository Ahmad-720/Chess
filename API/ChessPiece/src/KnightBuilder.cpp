#include "../include/KnightBuilder.hpp"

std::unique_ptr<ChessPiece> KnightBuilder::create(ChessPieceColor color)
{
    auto chessPiece = std::make_unique<ChessPiece>();

    setChessPieceName(*chessPiece, ChessPieceName::Knight);
    setChessPieceVision(*chessPiece, ChessPieceVision::LShape);
    setChessPieceNotation(*chessPiece, 'N');
    setChessPieceColor(*chessPiece, color);

    return chessPiece;
}