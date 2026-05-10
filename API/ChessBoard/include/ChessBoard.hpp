#pragma once

#include "../../ChessPiece/include/fwd.hpp"

#include <memory>
#include <vector>

class ChessBoard
{
private:
    std::vector<std::vector<std::unique_ptr<ChessPiece>>> m_board;
    ChessBoard() = default;

public:
    static ChessBoard createTraditionalChessBoard();
    static ChessBoard createEmptyChessBoard();

    const auto &getBoard() const { return m_board; }
};