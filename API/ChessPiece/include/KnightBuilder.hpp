#pragma once

#include "ChessPieceBuilder.hpp"

class KnightBuilder : public ChessPieceBuilder
{
public:
    std::unique_ptr<ChessPiece> create(ChessPieceColor color) const override;
};