#include "../ChessBoard/include/ChessBoard.hpp"
#include "../ChessBoard/include/ChessBoardUtilities.hpp"

#include "../ChessPiece/include/ChessPiece.hpp"
#include "../ChessPiece/include/KingBuilder.hpp"
#include "../ChessPiece/include/QueenBuilder.hpp"
#include "../ChessPiece/include/PawnBuilder.hpp"
#include "../ChessPiece/include/BishopBuilder.hpp"
#include "../ChessPiece/include/KnightBuilder.hpp"
#include "../ChessPiece/include/RookBuilder.hpp"

#include <iostream>

namespace test
{
    bool createEmptyChessBoardTest()
    {
        const auto chessBoard = ChessBoard::createEmptyChessBoard();

        constexpr int rows = 8;
        constexpr int columns = 8;

        for (int row = 0; row < rows; ++row)
            for (int column = 0; column < columns; ++column)
                if (chessBoard.getBoard().at(row).at(column) != nullptr)
                {
                    std::cerr << "The Board is not empty\n";
                    return false;
                }

        std::cout << "createEmptyChessBoard PASSED\n";
        return true;
    }

    bool createTraditionalBoardTest()
    {
        bool testPassed = true;
        const auto chessBoard = ChessBoard::createTraditionalChessBoard();

        // Black Pieces

        const auto *chessPiece = chessBoard.getBoard().at(0).at(0).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Rook || chessPiece->getColor() != ChessPieceColor::Black)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(0).at(7).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Rook || chessPiece->getColor() != ChessPieceColor::Black)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(0).at(1).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Knight || chessPiece->getColor() != ChessPieceColor::Black)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(0).at(6).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Knight || chessPiece->getColor() != ChessPieceColor::Black)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(0).at(2).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Bishop || chessPiece->getColor() != ChessPieceColor::Black)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(0).at(5).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Bishop || chessPiece->getColor() != ChessPieceColor::Black)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(0).at(3).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Queen || chessPiece->getColor() != ChessPieceColor::Black)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(0).at(4).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::King || chessPiece->getColor() != ChessPieceColor::Black)
            testPassed = false;

        // White Pieces

        chessPiece = chessBoard.getBoard().at(7).at(0).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Rook || chessPiece->getColor() != ChessPieceColor::White)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(7).at(7).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Rook || chessPiece->getColor() != ChessPieceColor::White)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(7).at(1).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Knight || chessPiece->getColor() != ChessPieceColor::White)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(7).at(6).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Knight || chessPiece->getColor() != ChessPieceColor::White)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(7).at(2).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Bishop || chessPiece->getColor() != ChessPieceColor::White)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(7).at(5).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Bishop || chessPiece->getColor() != ChessPieceColor::White)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(7).at(3).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::Queen || chessPiece->getColor() != ChessPieceColor::White)
            testPassed = false;

        chessPiece = chessBoard.getBoard().at(7).at(4).get();

        if (!chessPiece || chessPiece->getName() != ChessPieceName::King || chessPiece->getColor() != ChessPieceColor::White)
            testPassed = false;

        for (int column = 0; column < 8; ++column)
        {
            const auto *blackPawn = chessBoard.getBoard().at(1).at(column).get();
            const auto *whitePawn = chessBoard.getBoard().at(6).at(column).get();

            if (!blackPawn || blackPawn->getName() != ChessPieceName::Pawn || blackPawn->getColor() != ChessPieceColor::Black)
                testPassed = false;

            if (!whitePawn || whitePawn->getName() != ChessPieceName::Pawn || whitePawn->getColor() != ChessPieceColor::White)
                testPassed = false;
        }

        if (testPassed)
            std::cout << "createTraditionBoard PASSED\n";

        return testPassed;
    }

    bool getSquareFromRowAndColumnTest()
    {

        int currentRow = 8;
        char currentColumn = 'a';

        for (int row = 0; row < 8; ++row)
        {
            char currentColumn = 'a';
            for (int column = 0; column < 8; ++column)
            {
                if (getSquareFromRowAndColumn(row, column) != Square{currentColumn, currentRow})
                {
                    std::cerr << "ERROR OCCURED: Converting from index to Square gone wrong\n";
                    return false;
                }
                currentColumn += 1;
            }
            currentRow -= 1;
        }

        std::cout << "getSquareFromRowAndColumnTest PASSED\n";

        return true;
    }

    bool isKingInCheckTest()
    {
        const std::string failureMessage = "isKingInCheckTest FAILED\n";

        // ─── Baseline: same-color queen does not check own king ───────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({7, 0}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 0}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Baseline: same-color queen should not check own king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Queen checks king along file (vertical) ──────────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({7, 0}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 0}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Queen on same file should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Queen checks king along rank (horizontal) ────────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({4, 0}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Queen on same rank should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Queen checks king along diagonal ────────────────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({7, 0}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 7}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Queen on diagonal should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Rook checks king along file ──────────────────────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Rook on same file should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Rook checks king along rank ──────────────────────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({4, 7}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Rook on same rank should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Rook cannot check diagonally ─────────────────────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({2, 2}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Rook on diagonal should NOT check king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Bishop checks king along diagonal ───────────────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({1, 1}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Bishop on diagonal should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Bishop cannot check along file or rank ───────────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({4, 0}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Bishop on same rank should NOT check king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Pawn checks king (white king, black pawn attacks diagonally down) ────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 5}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Black pawn diagonally adjacent should check white king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Pawn does not check king from straight ahead ─────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Black pawn directly ahead should NOT check white king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Knight checks from all 8 positions ───────────────────────────────────
        // Knight at king+( 2, 1)
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({6, 5}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Knight at offset (+2,+1) should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // Knight at king+( 2,-1)
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({6, 3}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Knight at offset (+2,-1) should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // Knight at king+(-2, 1)
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({2, 5}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Knight at offset (-2,+1) should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // Knight at king+(-2,-1)
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({2, 3}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Knight at offset (-2,-1) should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // Knight at king+( 1, 2)
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({5, 6}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Knight at offset (+1,+2) should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // Knight at king+( 1,-2)
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({5, 2}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Knight at offset (+1,-2) should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // Knight at king+(-1, 2)
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 6}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Knight at offset (-1,+2) should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // Knight at king+(-1,-2)
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 2}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Knight at offset (-1,-2) should check king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Friendly piece blocks sliding piece check (file) ────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            // Friendly rook sits between king and enemy rook on the same file
            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({2, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Friendly piece on file should block enemy rook check\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Enemy piece blocks another sliding piece check (file) ───────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            // Enemy pawn sits between king and enemy rook — rook is blocked
            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({2, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Enemy piece on file should also block enemy rook check\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Friendly piece blocks bishop diagonal ────────────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({1, 1}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Friendly piece on diagonal should block enemy bishop check\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Friendly piece blocks queen diagonal ─────────────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({5, 5}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({7, 7}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Friendly piece on diagonal should block enemy queen check\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── Black king checked by white rook ─────────────────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({0, 0}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 7}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::Black))
            {
                std::cerr << "White rook on same rank should check black king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── King not in check on empty board (only king) ─────────────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (chessBoard.isKingInCheck(ChessPieceColor::White))
            {
                std::cerr << "Lone king should not be in check\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── White pawn checks black king (attacks upward = decreasing row index) ────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({5, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isKingInCheck(ChessPieceColor::Black))
            {
                std::cerr << "White pawn diagonally adjacent (higher row index) should check black king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── White pawn does not check black king from straight ahead ─────────────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({5, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (chessBoard.isKingInCheck(ChessPieceColor::Black))
            {
                std::cerr << "White pawn directly behind (higher row index) should NOT check black king\n"
                          << failureMessage;
                return false;
            }
        }

        // ─── White pawn on wrong diagonal direction does not check black king ─────────
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            // White pawn at a lower row index than the king — it would be "above" the king,
            // meaning it's attacking away from the king, not toward it
            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            if (chessBoard.isKingInCheck(ChessPieceColor::Black))
            {
                std::cerr << "White pawn on wrong diagonal direction should NOT check black king\n"
                          << failureMessage;
                return false;
            }
        }

        std::cout << "isKingInCheckTest PASSED\n";
        return true;
    }

    bool isPiecePinnedTest()
    {
        using Direction = DirectionInWhitePerspective;

        const std::string failureMessage = "isPiecePinnedTest FAILED\n";

        // Coordinate system (0-indexed, 0->7 for both rows and cols):
        //   higher col → Right,   lower col → Left
        //   lower  row → Forward, higher row → Backward (confirmed: LowerRight test has attacker at higher row)

        // =========================================================
        // GROUP 1: Valid pins — all 8 directions
        // =========================================================

        // [1] Pinned from Right by Queen
        // King {2,2}, Rook {2,3}, Queen {2,7} — attacker col 7 > pinned col 3 → Right
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({2, 2}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({2, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({2, 7}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({2, 3}, &directionPinnedFrom) && directionPinnedFrom == Direction::Right)
                ;
            else
            {
                std::cerr << "[1] White Rook should be pinned to the king by the black Queen from the Right\n"
                          << failureMessage;
                return false;
            }
        }

        // [2] Pinned from Left by Queen
        // King {2,5}, Bishop {2,3}, Queen {2,0} — attacker col 0 < pinned col 3 → Left
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({2, 5}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({2, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({2, 0}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({2, 3}, &directionPinnedFrom) && directionPinnedFrom == Direction::Left)
                ;
            else
            {
                std::cerr << "[2] White Bishop should be pinned to the king by the black Queen from the Left\n"
                          << failureMessage;
                return false;
            }
        }

        // [3] Pinned from Forward by Rook
        // King {6,4}, Knight {4,4}, Rook {0,4} — attacker row 0 < pinned row 4 → Forward
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({6, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({4, 4}, &directionPinnedFrom) && directionPinnedFrom == Direction::Forward)
                ;
            else
            {
                std::cerr << "[3] White Knight should be pinned to the king by the black Rook from Forward\n"
                          << failureMessage;
                return false;
            }
        }

        // [4] Pinned from Backward by Rook
        // King {1,4}, Pawn {4,4}, Rook {6,4} — attacker row 6 > pinned row 4 → Backward
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({1, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({4, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({6, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({4, 4}, &directionPinnedFrom) && directionPinnedFrom == Direction::Backward)
                ;
            else
            {
                std::cerr << "[4] White Pawn should be pinned to the king by the black Rook from Backward\n"
                          << failureMessage;
                return false;
            }
        }

        // [5] Pinned from LowerRight by Bishop
        // King {2,2}, Rook {3,3}, Bishop {7,7} — attacker row 7 > pinned row 3 (Lower), col 7 > col 3 (Right) → LowerRight
        // (original passing test from schema)
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({2, 2}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({7, 7}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 3}, &directionPinnedFrom) && directionPinnedFrom == Direction::LowerRight)
                ;
            else
            {
                std::cerr << "[5] White Rook should be pinned to the king by the black Bishop from LowerRight\n"
                          << failureMessage;
                return false;
            }
        }

        // [6] Pinned from UpperLeft by Bishop
        // King {5,5}, Queen {3,3}, Bishop {1,1} — attacker row 1 < pinned row 3 (Upper), col 1 < col 3 (Left) → UpperLeft
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({5, 5}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({1, 1}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 3}, &directionPinnedFrom) && directionPinnedFrom == Direction::UpperLeft)
                ;
            else
            {
                std::cerr << "[6] White Queen should be pinned to the king by the black Bishop from UpperLeft\n"
                          << failureMessage;
                return false;
            }
        }

        // [7] Pinned from LowerLeft by Queen
        // King {1,5}, Pawn {3,3}, Queen {5,1} — attacker row 5 > pinned row 3 (Lower), col 1 < col 3 (Left) → LowerLeft
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({1, 5}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({5, 1}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 3}, &directionPinnedFrom) && directionPinnedFrom == Direction::LowerLeft)
                ;
            else
            {
                std::cerr << "[7] White Pawn should be pinned to the king by the black Queen from LowerLeft\n"
                          << failureMessage;
                return false;
            }
        }

        // [8] Pinned from UpperRight by Bishop
        // King {5,1}, Knight {3,3}, Bishop {1,5} — attacker row 1 < pinned row 3 (Upper), col 5 > col 3 (Right) → UpperRight
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({5, 1}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({1, 5}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 3}, &directionPinnedFrom) && directionPinnedFrom == Direction::UpperRight)
                ;
            else
            {
                std::cerr << "[8] White Knight should be pinned to the king by the black Bishop from UpperRight\n"
                          << failureMessage;
                return false;
            }
        }

        // =========================================================
        // GROUP 2: Not pinned — piece is not between king and attacker
        // =========================================================

        // [9] Attacker on the opposite side of the king from the piece
        // King {3,3}, Rook {3,5}, Queen {3,0} — queen is left of king, rook is right of king
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 5}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 0}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (!chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 5}, &directionPinnedFrom))
                ;
            else
            {
                std::cerr << "[9] White Rook should NOT be pinned — attacker is on the opposite side of the king\n"
                          << failureMessage;
                return false;
            }
        }

        // [10] Two friendly pieces between king and attacker — neither is pinned
        // King {3,0}, Rook {3,2}, Bishop {3,4}, Queen {3,7}
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({3, 0}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 2}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 7}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (!chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 2}, &directionPinnedFrom))
                ;
            else
            {
                std::cerr << "[10] White Rook at (3,2) should NOT be pinned — two pieces between king and attacker\n"
                          << failureMessage;
                return false;
            }

            if (!chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 4}, &directionPinnedFrom))
                ;
            else
            {
                std::cerr << "[10] White Bishop at (3,4) should NOT be pinned — two pieces between king and attacker\n"
                          << failureMessage;
                return false;
            }
        }

        // =========================================================
        // GROUP 3: Wrong attacker type — piece cannot pin on that ray
        // =========================================================

        // [11] Rook on a diagonal — cannot pin diagonally
        // King {1,1}, Pawn {3,3}, Rook {5,5}
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({1, 1}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({5, 5}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (!chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 3}, &directionPinnedFrom))
                ;
            else
            {
                std::cerr << "[11] White Pawn should NOT be pinned — black Rook cannot pin along a diagonal\n"
                          << failureMessage;
                return false;
            }
        }

        // [12] Bishop on a rank — cannot pin horizontally
        // King {3,1}, Knight {3,4}, Bishop {3,6}
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({3, 1}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 6}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (!chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 4}, &directionPinnedFrom))
                ;
            else
            {
                std::cerr << "[12] White Knight should NOT be pinned — black Bishop cannot pin along a rank\n"
                          << failureMessage;
                return false;
            }
        }

        // [13] Bishop on a file — cannot pin vertically
        // King {6,3}, Rook {3,3}, Bishop {0,3}
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({6, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 3}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (!chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 3}, &directionPinnedFrom))
                ;
            else
            {
                std::cerr << "[13] White Rook should NOT be pinned — black Bishop cannot pin along a file\n"
                          << failureMessage;
                return false;
            }
        }

        // [14] Knight as attacker — Knights cannot pin
        // King {3,3}, Rook {3,5}, Knight {3,7}
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 5}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KnightBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 7}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (!chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 5}, &directionPinnedFrom))
                ;
            else
            {
                std::cerr << "[14] White Rook should NOT be pinned — Knights cannot pin pieces\n"
                          << failureMessage;
                return false;
            }
        }

        // [15] Pawn as attacker — Pawns cannot pin
        // King {3,3}, Bishop {3,5}, Pawn {3,7}
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 5}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<PawnBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 7}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (!chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 5}, &directionPinnedFrom))
                ;
            else
            {
                std::cerr << "[15] White Bishop should NOT be pinned — Pawns cannot pin pieces\n"
                          << failureMessage;
                return false;
            }
        }

        // =========================================================
        // GROUP 4: Pinned to the opposite color king
        // =========================================================

        // [16] Black piece pinned to black king by white Queen
        // Black King {6,6}, Black Rook {6,4}, White Queen {6,0} — attacker col 0 < pinned col 4 → Left
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({6, 6}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({6, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({6, 0}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({6, 4}, &directionPinnedFrom) && directionPinnedFrom == Direction::Left)
                ;
            else
            {
                std::cerr << "[16] Black Rook should be pinned to the black king by the white Queen from the Left\n"
                          << failureMessage;
                return false;
            }
        }

        // [17] White piece on ray between black king and black attacker — NOT pinned (own white king is elsewhere)
        // White King {0,0}, Black King {6,6}, White Rook {6,4}, Black Queen {6,0}
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({0, 0}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<KingBuilder>();
            if (!chessBoard.insertChessPieceAt({6, 6}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({6, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({6, 0}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (!chessBoard.isChessPieceOnRowAndColumnIndexesPinned({6, 4}, &directionPinnedFrom))
                ;
            else
            {
                std::cerr << "[17] White Rook should NOT be pinned — its own king is not on this ray\n"
                          << failureMessage;
                return false;
            }
        }

        // =========================================================
        // GROUP 5: Friendly attacker — cannot create a pin
        // =========================================================

        // [18] Friendly Queen behind the piece — does not pin
        // King {3,3}, Bishop {3,5}, White Queen {3,7}
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 5}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 7}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (!chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 5}, &directionPinnedFrom))
                ;
            else
            {
                std::cerr << "[18] White Bishop should NOT be pinned — attacker is a friendly piece\n"
                          << failureMessage;
                return false;
            }
        }

        // =========================================================
        // GROUP 6: No attacker present
        // =========================================================

        // [19] No enemy piece on the ray — not pinned
        // King {3,3}, Rook {3,5}, nothing beyond
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 5}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (!chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 5}, &directionPinnedFrom))
                ;
            else
            {
                std::cerr << "[19] White Rook should NOT be pinned — no attacker present\n"
                          << failureMessage;
                return false;
            }
        }

        // =========================================================
        // GROUP 7: Edge of board cases
        // =========================================================

        // [20] Pin along row 0 (top edge)
        // King {0,0}, Rook {0,3}, Queen {0,7} — attacker col 7 > pinned col 3 → Right
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({0, 0}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 7}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({0, 3}, &directionPinnedFrom) && directionPinnedFrom == Direction::Right)
                ;
            else
            {
                std::cerr << "[20] White Rook should be pinned along row 0 from the Right\n"
                          << failureMessage;
                return false;
            }
        }

        // [21] Pin along col 7 (right edge)
        // King {7,7}, Bishop {4,7}, Queen {0,7} — attacker row 0 < pinned row 4 → Forward
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({7, 7}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({4, 7}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({0, 7}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({4, 7}, &directionPinnedFrom) && directionPinnedFrom == Direction::Forward)
                ;
            else
            {
                std::cerr << "[21] White Bishop should be pinned along col 7 from Forward\n"
                          << failureMessage;
                return false;
            }
        }

        // [22] King directly adjacent to pinned piece (no gap between them)
        // King {3,3}, Rook {3,4}, Queen {3,7} — attacker col 7 > pinned col 4 → Right
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<RookBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 4}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 7}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 4}, &directionPinnedFrom) && directionPinnedFrom == Direction::Right)
                ;
            else
            {
                std::cerr << "[22] White Rook adjacent to king should be pinned from the Right\n"
                          << failureMessage;
                return false;
            }
        }

        // [23] Attacker directly adjacent to pinned piece (no gap between attacker and pinned piece)
        // King {3,0}, Bishop {3,3}, Queen {3,4} — attacker col 4 > pinned col 3 → Right
        {
            ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
            std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

            if (!chessBoard.insertChessPieceAt({3, 0}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<BishopBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 3}, *builder, ChessPieceColor::White))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            builder = std::make_unique<QueenBuilder>();
            if (!chessBoard.insertChessPieceAt({3, 4}, *builder, ChessPieceColor::Black))
            {
                std::cerr << "could not insert Chess Piece\n"
                          << failureMessage;
                return false;
            }

            Direction directionPinnedFrom;
            if (chessBoard.isChessPieceOnRowAndColumnIndexesPinned({3, 3}, &directionPinnedFrom) && directionPinnedFrom == Direction::Right)
                ;
            else
            {
                std::cerr << "[23] White Bishop should be pinned when attacker is directly adjacent from the Right\n"
                          << failureMessage;
                return false;
            }
        }

        return true;
    }
} // namespace test

int main()
{
    bool allPassed = test::createEmptyChessBoardTest();
    allPassed = allPassed && test::createTraditionalBoardTest();
    allPassed = allPassed && test::getSquareFromRowAndColumnTest();
    allPassed = allPassed && test::isKingInCheckTest();
    allPassed = allPassed && test::isPiecePinnedTest();

    if (allPassed)
        std::cout << "All Tests Passed Successfully\n";
    return 0;
}