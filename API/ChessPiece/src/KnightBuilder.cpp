#include "../include/KnightBuilder.hpp"

std::unique_ptr<ChessPiece> KnightBuilder::create()
{
    auto chessPiece = std::make_unique<ChessPiece>();

    setChessPieceName(*chessPiece, ChessPieceName::Knight);
    setChessPieceVision(*chessPiece, ChessPieceVision::LShape);
    setChessPieceNotation(*chessPiece, 'N');

    return chessPiece;
}