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
        ChessBoard chessBoard = ChessBoard::createEmptyChessBoard();
        std::unique_ptr<ChessPieceBuilder> builder = std::make_unique<KingBuilder>();

        if (!chessBoard.insertChessPieceAt({7, 0}, *builder, ChessPieceColor::White))
        {
            std::cerr << "could not insert Chess Piece\n";
            std::cerr << failureMessage;
            return false;
        }

        builder = std::make_unique<QueenBuilder>();

        if (!chessBoard.insertChessPieceAt({0, 0}, *builder, ChessPieceColor::White))
        {
            std::cerr << "could not insert Chess Piece\n";
            std::cerr << failureMessage;
            return false;
        }

        if (chessBoard.isKingInCheck(ChessPieceColor::White))
        {
            std::cerr << "The White King Should not be in Check\n";
            std::cerr << failureMessage;
            return false;
        }

        chessBoard = ChessBoard::createEmptyChessBoard();
        builder = std::make_unique<KingBuilder>();

        if (!chessBoard.insertChessPieceAt({7, 0}, *builder, ChessPieceColor::White))
        {
            std::cerr << "could not insert Chess Piece\n";
            std::cerr << failureMessage;
            return false;
        }

        builder = std::make_unique<QueenBuilder>();

        if (!chessBoard.insertChessPieceAt({0, 7}, *builder, ChessPieceColor::Black))
        {
            std::cerr << "could not insert Chess Piece\n";
            std::cerr << failureMessage;
            return false;
        }

        if (!chessBoard.isKingInCheck(ChessPieceColor::White))
        {
            std::cerr << "The White King Should be in Check\n";
            std::cerr << failureMessage;
            return false;
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