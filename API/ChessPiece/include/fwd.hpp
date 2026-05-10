#pragma once

class ChessPiece;
class ChessPieceBuilder;

enum class ChessPieceName
{
    Pawn,
    Knight,
    Bishop,
    Rook,
    King,
    Queen
};

enum class ChessPieceVision
{
    Front,
    Diagonal,
    Straight,
    LShape,
    AllDirections,
    Square
};

enum class ChessPieceColor
{
    White,
    Black
};