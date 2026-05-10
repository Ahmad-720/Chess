#pragma once

#include "ChessPieceBuilder.hpp"

class QueenBuilder : public ChessPieceBuilder
{
public:
    std::unique_ptr<ChessPiece> create(ChessPieceColor color) override;
};