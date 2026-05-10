#pragma once

#include "ChessPieceBuilder.hpp"

class BishopBuilder : public ChessPieceBuilder
{
public:
    std::unique_ptr<ChessPiece> create(ChessPieceColor color) override;
};