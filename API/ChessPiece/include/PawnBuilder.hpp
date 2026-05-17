#pragma once

#include "ChessPieceBuilder.hpp"

class PawnBuilder : public ChessPieceBuilder
{
public:
    std::unique_ptr<ChessPiece> create(ChessPieceColor color) const override;
};