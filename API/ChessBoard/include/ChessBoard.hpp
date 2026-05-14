#pragma once

#include "../../ChessPiece/include/fwd.hpp"

#include <memory>
#include <vector>

class ChessBoard
{
private:
    std::vector<std::vector<std::unique_ptr<ChessPiece>>> m_board;
    std::pair<int, int> m_blackKingCurrentPosition = {-1, -1};
    std::pair<int, int> m_whiteKingCurrentPosition = {-1, -1};
    ChessBoard() = default;

    bool kingExists(ChessPieceColor chessPieceColor);

public:
    static ChessBoard createTraditionalChessBoard();
    static ChessBoard createEmptyChessBoard();

    const auto &getBoard() const { return m_board; }
};