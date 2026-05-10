#pragma once

#include "ChessPieceBuilder.hpp"

class KingBuilder : public ChessPieceBuilder
{
public:
    std::unique_ptr<ChessPiece> create(ChessPieceColor color) override;
};