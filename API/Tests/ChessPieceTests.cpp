#include "../ChessPiece/include/ChessPiece.hpp"
#include "../ChessPiece/include/PawnBuilder.hpp"
#include "../ChessPiece/include/KnightBuilder.hpp"
#include "../ChessPiece/include/BishopBuilder.hpp"
#include "../ChessPiece/include/RookBuilder.hpp"
#include "../ChessPiece/include/KingBuilder.hpp"
#include "../ChessPiece/include/QueenBuilder.hpp"

#include <iostream>

namespace test
{
    static std::unique_ptr<ChessPieceBuilder> builder;

    bool createPawn()
    {
        bool testPassed = true;
        builder = std::make_unique<PawnBuilder>();

        const auto pawn = builder->create(ChessPieceColor::White);

        if (pawn->getName() != ChessPieceName::Pawn)
        {
            std::cerr << "The Pawn must be created under the name 'Pawn'\n";
            testPassed = false;
        }

        if (pawn->getVision() != ChessPieceVision::Front)
        {
            std::cerr << "The Pawn must have the 'Front' vision";
            testPassed = false;
        }

        if (pawn->getNotation() != ' ')
        {
            std::cerr << "A Pawn must have an empty notation\n";
            testPassed = false;
        }

        if (pawn->hasMoved())
        {
            std::cerr << "A Pawn that was just created could not have moved";
            testPassed = false;
        }

        return testPassed;
    }

    bool createKnight()
    {
        bool testPassed = true;
        builder = std::make_unique<KnightBuilder>();

        const auto knight = builder->create(ChessPieceColor::White);

        if (knight->getName() != ChessPieceName::Knight)
        {
            std::cerr << "The knight must be created under the name 'knight'\n";
            testPassed = false;
        }

        if (knight->getVision() != ChessPieceVision::LShape)
        {
            std::cerr << "The knight must have the 'LShape' vision";
            testPassed = false;
        }

        if (knight->getNotation() != 'N')
        {
            std::cerr << "A Knight must have the notation 'N'\n";
            testPassed = false;
        }

        if (knight->hasMoved())
        {
            std::cerr << "A knight that was just created could not have moved";
            testPassed = false;
        }

        return testPassed;
    }

    bool createBishop()
    {
        bool testPassed = true;
        builder = std::make_unique<BishopBuilder>();

        const auto bishop = builder->create(ChessPieceColor::White);

        if (bishop->getName() != ChessPieceName::Bishop)
        {
            std::cerr << "The Bishop must be created under the name 'Bishop'\n";
            testPassed = false;
        }

        if (bishop->getVision() != ChessPieceVision::Diagonal)
        {
            std::cerr << "The Bishop must have the 'Diagonal' vision";
            testPassed = false;
        }

        if (bishop->getNotation() != 'B')
        {
            std::cerr << "The Bishop must have the notation 'B'\n";
            testPassed = false;
        }

        if (bishop->hasMoved())
        {
            std::cerr << "A Bishop that was just created could not have moved";
            testPassed = false;
        }

        return testPassed;
    }

    bool createRook()
    {
        bool testPassed = true;
        builder = std::make_unique<RookBuilder>();

        const auto rook = builder->create(ChessPieceColor::White);

        if (rook->getName() != ChessPieceName::Rook)
        {
            std::cerr << "The Rook must be created under the name 'Rook'\n";
            testPassed = false;
        }

        if (rook->getVision() != ChessPieceVision::Straight)
        {
            std::cerr << "The Rook must have the 'Straight' vision";
            testPassed = false;
        }

        if (rook->getNotation() != 'R')
        {
            std::cerr << "The Rook must have the notation 'R'\n";
            testPassed = false;
        }

        if (rook->hasMoved())
        {
            std::cerr << "A Rook that was just created could not have moved";
            testPassed = false;
        }

        return testPassed;
    }

    bool createKing()
    {
        bool testPassed = true;
        builder = std::make_unique<KingBuilder>();

        const auto king = builder->create(ChessPieceColor::White);

        if (king->getName() != ChessPieceName::King)
        {
            std::cerr << "The King must be created under the name 'King'\n";
            testPassed = false;
        }

        if (king->getVision() != ChessPieceVision::Square)
        {
            std::cerr << "The King must have the 'Square' vision";
            testPassed = false;
        }

        if (king->getNotation() != 'K')
        {
            std::cerr << "The King must have the notation 'K'\n";
            testPassed = false;
        }

        if (king->hasMoved())
        {
            std::cerr << "A King that was just created could not have moved";
            testPassed = false;
        }

        return testPassed;
    }

    bool createQueen()
    {
        bool testPassed = true;
        builder = std::make_unique<QueenBuilder>();

        const auto queen = builder->create(ChessPieceColor::White);

        if (queen->getName() != ChessPieceName::Queen)
        {
            std::cerr << "The Queen must be created under the name 'Queen'\n";
            testPassed = false;
        }

        if (queen->getVision() != ChessPieceVision::AllDirections)
        {
            std::cerr << "The Queen must have the 'AllDirections' vision";
            testPassed = false;
        }

        if (queen->getNotation() != 'Q')
        {
            std::cerr << "The Queen must have the notation 'Q'\n";
            testPassed = false;
        }

        if (queen->hasMoved())
        {
            std::cerr << "A Queen that was just created could not have moved";
            testPassed = false;
        }

        return testPassed;
    }

} // namespace test

int main()
{
    bool testPassed = test::createPawn();
    testPassed = testPassed && test::createKnight();
    testPassed = testPassed && test::createBishop();
    testPassed = testPassed && test::createRook();
    testPassed = testPassed && test::createKing();
    testPassed = testPassed && test::createQueen();

    if (testPassed)
        std::cout << "All tests have passed successfully\n";

    return testPassed;
}