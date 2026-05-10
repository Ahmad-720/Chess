#pragma once

#include "fwd.hpp"

class ChessPiece
{
private:
    ChessPieceName m_name;
    ChessPieceVision m_vision;
    ChessPieceColor m_color;
    bool m_hasMoved = false;
    char m_notation;

public:
    ChessPieceName getName() const { return m_name; }
    ChessPieceVision getVision() const { return m_vision; }
    ChessPieceColor getColor() const { return m_color; }
    char getNotation() const { return m_notation; }
    bool hasMoved() const { return m_hasMoved; }
    void move() { m_hasMoved = true; }

    friend class ChessPieceBuilder;
};