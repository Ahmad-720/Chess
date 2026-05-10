#include "../include/KingBuilder.hpp"

std::unique_ptr<ChessPiece> KingBuilder::create(ChessPieceColor color)
{
    auto chessPiece = std::make_unique<ChessPiece>();

    setChessPieceName(*chessPiece, ChessPieceName::King);
    setChessPieceVision(*chessPiece, ChessPieceVision::Square);
    setChessPieceNotation(*chessPiece, 'K');
    setChessPieceColor(*chessPiece, color);

    return chessPiece;
}