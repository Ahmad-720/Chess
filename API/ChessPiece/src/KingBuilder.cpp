#include "../include/KingBuilder.hpp"

std::unique_ptr<ChessPiece> KingBuilder::create()
{
    auto chessPiece = std::make_unique<ChessPiece>();

    setChessPieceName(*chessPiece, ChessPieceName::King);
    setChessPieceVision(*chessPiece, ChessPieceVision::Square);
    setChessPieceNotation(*chessPiece, 'K');

    return chessPiece;
}