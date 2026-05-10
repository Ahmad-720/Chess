#pragma once

#include "ChessPieceBuilder.hpp"

class RookBuilder : public ChessPieceBuilder
{
public:
    std::unique_ptr<ChessPiece> create(ChessPieceColor color) override;
};