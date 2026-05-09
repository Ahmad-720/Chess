#pragma once

#include "fwd.hpp"
#include "ChessPiece.hpp"

#include <memory>

class ChessPieceBuilder
{
public:
    virtual std::unique_ptr<ChessPiece> create() = 0;

protected:
    void setChessPieceName(ChessPiece &piece, ChessPieceName name) { piece.m_name = name; }
    void setChessPieceVision(ChessPiece &piece, ChessPieceVision vision) { piece.m_vision = vision; }
    void setChessPieceNotation(ChessPiece &piece, char notation) { piece.m_notation = notation; }
};