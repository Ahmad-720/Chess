#include "../include/QueenBuilder.hpp"

std::unique_ptr<ChessPiece> QueenBuilder::create(ChessPieceColor color)
{
    auto chessPiece = std::make_unique<ChessPiece>();

    setChessPieceName(*chessPiece, ChessPieceName::Queen);
    setChessPieceVision(*chessPiece, ChessPieceVision::AllDirections);
    setChessPieceNotation(*chessPiece, 'Q');
    setChessPieceColor(*chessPiece, color);

    return chessPiece;
}