#include "../include/BishopBuilder.hpp"

std::unique_ptr<ChessPiece> BishopBuilder::create()
{
    auto chessPiece = std::make_unique<ChessPiece>();

    setChessPieceName(*chessPiece, ChessPieceName::Bishop);
    setChessPieceVision(*chessPiece, ChessPieceVision::Diagonal);
    setChessPieceNotation(*chessPiece, 'B');

    return chessPiece;
}