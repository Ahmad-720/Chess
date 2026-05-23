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
} // namespace test

int main()
{
    bool allPassed = test::createEmptyChessBoardTest();
    allPassed = allPassed && test::createTraditionalBoardTest();
    allPassed = allPassed && test::getSquareFromRowAndColumnTest();
    allPassed = allPassed && test::isKingInCheckTest();

    if (allPassed)
        std::cout << "All Tests Passed Successfully\n";
    return 0;
}