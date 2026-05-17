#pragma once

#include "fwd.hpp"
#include "ChessPiece.hpp"

#include <memory>

class ChessPieceBuilder
{
public:
    virtual std::unique_ptr<ChessPiece> create(ChessPieceColor color) const = 0;

protected:
    void setChessPieceName(ChessPiece &piece, ChessPieceName name) const { piece.m_name = name; }
    void setChessPieceVision(ChessPiece &piece, ChessPieceVision vision) const { piece.m_vision = vision; }
    void setChessPieceNotation(ChessPiece &piece, char notation) const { piece.m_notation = notation; }
    void setChessPieceColor(ChessPiece &piece, ChessPieceColor color) const { piece.m_color = color; }
};