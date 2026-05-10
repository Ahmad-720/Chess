#include "../ChessBoard/include/ChessBoard.hpp"

#include "../ChessPiece/include/ChessPiece.hpp"

#include <iostream>

namespace test
{
    bool createEmptyChessBoard()
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

    bool createTraditionalBoard()
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
} // namespace test

int main()
{
    bool allPassed = test::createEmptyChessBoard();
    allPassed = allPassed && test::createTraditionalBoard();

    if (allPassed)
        std::cout << "All Tests Passed Successfully\n";
    return 0;
}