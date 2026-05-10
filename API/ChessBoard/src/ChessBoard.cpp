#include "../include/ChessBoard.hpp"

#include "../../ChessPiece/include/ChessPiece.hpp"
#include "../../ChessPiece/include/PawnBuilder.hpp"
#include "../../ChessPiece/include/KnightBuilder.hpp"
#include "../../ChessPiece/include/BishopBuilder.hpp"
#include "../../ChessPiece/include/RookBuilder.hpp"
#include "../../ChessPiece/include/KingBuilder.hpp"
#include "../../ChessPiece/include/QueenBuilder.hpp"

ChessBoard ChessBoard::createEmptyChessBoard()
{
    ChessBoard chessBoard;
    chessBoard.m_board.reserve(8);

    constexpr int rows = 8;
    constexpr int columns = 8;

    for (int row = 0; row < rows; ++row)
    {
        chessBoard.m_board.push_back(std::vector<std::unique_ptr<ChessPiece>>());
        chessBoard.m_board.at(row).reserve(8);
        for (int column = 0; column < columns; ++column)
            chessBoard.m_board.at(row).emplace_back(nullptr);
    }

    return chessBoard;
}

ChessBoard ChessBoard::createTraditionalChessBoard()
{
    ChessBoard chessBoard = createEmptyChessBoard();

    std::unique_ptr<ChessPieceBuilder> chessPieceBuilder = std::make_unique<PawnBuilder>();

    constexpr int columns = 8;

    for (int column = 0; column < columns; ++column)
    {
        chessBoard.m_board.at(1).at(column) = chessPieceBuilder->create(ChessPieceColor::Black);
        chessBoard.m_board.at(6).at(column) = chessPieceBuilder->create(ChessPieceColor::White);
    }

    chessPieceBuilder = std::make_unique<RookBuilder>();

    chessBoard.m_board.at(0).at(0) = chessPieceBuilder->create(ChessPieceColor::Black);
    chessBoard.m_board.at(0).at(7) = chessPieceBuilder->create(ChessPieceColor::Black);

    chessBoard.m_board.at(7).at(0) = chessPieceBuilder->create(ChessPieceColor::White);
    chessBoard.m_board.at(7).at(7) = chessPieceBuilder->create(ChessPieceColor::White);

    chessPieceBuilder = std::make_unique<KnightBuilder>();

    chessBoard.m_board.at(0).at(1) = chessPieceBuilder->create(ChessPieceColor::Black);
    chessBoard.m_board.at(0).at(6) = chessPieceBuilder->create(ChessPieceColor::Black);

    chessBoard.m_board.at(7).at(1) = chessPieceBuilder->create(ChessPieceColor::White);
    chessBoard.m_board.at(7).at(6) = chessPieceBuilder->create(ChessPieceColor::White);

    chessPieceBuilder = std::make_unique<BishopBuilder>();

    chessBoard.m_board.at(0).at(2) = chessPieceBuilder->create(ChessPieceColor::Black);
    chessBoard.m_board.at(0).at(5) = chessPieceBuilder->create(ChessPieceColor::Black);

    chessBoard.m_board.at(7).at(2) = chessPieceBuilder->create(ChessPieceColor::White);
    chessBoard.m_board.at(7).at(5) = chessPieceBuilder->create(ChessPieceColor::White);

    chessPieceBuilder = std::make_unique<KingBuilder>();

    chessBoard.m_board.at(0).at(4) = chessPieceBuilder->create(ChessPieceColor::Black);

    chessBoard.m_board.at(7).at(4) = chessPieceBuilder->create(ChessPieceColor::White);

    chessPieceBuilder = std::make_unique<QueenBuilder>();

    chessBoard.m_board.at(0).at(3) = chessPieceBuilder->create(ChessPieceColor::Black);

    chessBoard.m_board.at(7).at(3) = chessPieceBuilder->create(ChessPieceColor::White);

    return chessBoard;
}