#pragma once

#include "../../ChessPiece/include/fwd.hpp"

#include <memory>
#include <vector>

class ChessBoard
{
private:
    std::vector<std::vector<std::unique_ptr<ChessPiece>>> m_board;
    unsigned m_numebrOfRows = 0;
    unsigned m_numebrOfColumns = 0;
    std::pair<int, int> m_blackKingCurrentPosition = {-1, -1};
    std::pair<int, int> m_whiteKingCurrentPosition = {-1, -1};
    ChessBoard() = default;

    bool isKingExists(ChessPieceColor chessPieceColor) const;

public:
    static ChessBoard createTraditionalChessBoard();
    static ChessBoard createEmptyChessBoard();

    const auto &getBoard() const { return m_board; }
    unsigned getNumberOfRows() const { return m_numebrOfRows; }
    unsigned getNumberOfColumns() const { return m_numebrOfColumns; }
    const ChessPiece *getChessPieceAt(std::pair<int, int> rowAndColumnIndexes) const;

    const ChessPiece *insertChessPieceAt(std::pair<int, int> rowAndColumnIndexes, const ChessPieceBuilder &chessPieceBuilder, ChessPieceColor chessPieceColor); // added this function for testing, might get depcrecated later

    bool isKingInCheck(ChessPieceColor ChessPieceColor) const;
};