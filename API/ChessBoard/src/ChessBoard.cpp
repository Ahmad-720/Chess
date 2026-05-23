#include "../include/ChessBoard.hpp"

#include "../../ChessPiece/include/ChessPiece.hpp"
#include "../../ChessPiece/include/PawnBuilder.hpp"
#include "../../ChessPiece/include/KnightBuilder.hpp"
#include "../../ChessPiece/include/BishopBuilder.hpp"
#include "../../ChessPiece/include/RookBuilder.hpp"
#include "../../ChessPiece/include/KingBuilder.hpp"
#include "../../ChessPiece/include/QueenBuilder.hpp"

namespace
{
    enum class DirectionInWhitePerspective
    {
        Forward,
        UpperRight,
        Right,
        LowerRight,
        Backward,
        LowerLeft,
        Left,
        UpperLeft
    };

    DirectionInWhitePerspective &operator++(DirectionInWhitePerspective &direction)
    {
        if (direction == DirectionInWhitePerspective::UpperLeft)
            return direction;

        int valueOfDirection = static_cast<int>(direction);

        valueOfDirection += 1;
        direction = static_cast<DirectionInWhitePerspective>(valueOfDirection);

        return direction;
    }

    ChessPieceVision getVisionRelevantToDirection(DirectionInWhitePerspective direction)
    {
        using Direction = DirectionInWhitePerspective;

        switch (direction)
        {
        case Direction::Forward:
            return ChessPieceVision::Straight;

        case Direction::Backward:
            return ChessPieceVision::Straight;

        case Direction::Left:
            return ChessPieceVision::Straight;

        case Direction::Right:
            return ChessPieceVision::Straight;

        default:
            return ChessPieceVision::Diagonal;
        }
    }
} // namespace

ChessBoard ChessBoard::createEmptyChessBoard()
{
    ChessBoard chessBoard;
    chessBoard.m_numebrOfRows = 8;
    chessBoard.m_numebrOfColumns = 8;

    chessBoard.m_board.reserve(chessBoard.m_numebrOfRows);

    for (int row = 0; row < chessBoard.m_numebrOfRows; ++row)
    {
        chessBoard.m_board.push_back(std::vector<std::unique_ptr<ChessPiece>>());
        chessBoard.m_board.at(row).reserve(chessBoard.m_numebrOfColumns);
        for (int column = 0; column < chessBoard.m_numebrOfColumns; ++column)
            chessBoard.m_board.at(row).emplace_back(nullptr);
    }

    return chessBoard;
}

ChessBoard ChessBoard::createTraditionalChessBoard()
{
    ChessBoard chessBoard = createEmptyChessBoard();

    std::unique_ptr<ChessPieceBuilder> chessPieceBuilder = std::make_unique<PawnBuilder>();

    for (int column = 0; column < chessBoard.m_numebrOfColumns; ++column)
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
    chessBoard.m_blackKingCurrentPosition = {0, 4};

    chessBoard.m_board.at(7).at(4) = chessPieceBuilder->create(ChessPieceColor::White);
    chessBoard.m_whiteKingCurrentPosition = {7, 4};

    chessPieceBuilder = std::make_unique<QueenBuilder>();

    chessBoard.m_board.at(0).at(3) = chessPieceBuilder->create(ChessPieceColor::Black);

    chessBoard.m_board.at(7).at(3) = chessPieceBuilder->create(ChessPieceColor::White);

    return chessBoard;
}

bool ChessBoard::isKingExists(ChessPieceColor chessPieceColor) const
{
    if (chessPieceColor == ChessPieceColor::White)
        return m_whiteKingCurrentPosition.first != -1 && m_whiteKingCurrentPosition.second != -1;

    return m_blackKingCurrentPosition.first != -1 && m_blackKingCurrentPosition.second != -1;
}

static bool isRowAndColumnIndexesValid(const ChessBoard &chessBoard, std::pair<int, int> rowIndexColumnIndexPair)
{
    const auto rowIndex = rowIndexColumnIndexPair.first;
    const auto columnIndex = rowIndexColumnIndexPair.second;

    return rowIndex >= 0 && rowIndex < chessBoard.getNumberOfRows() && columnIndex >= 0 && columnIndex < chessBoard.getNumberOfColumns();
}

const ChessPiece *ChessBoard::insertChessPieceAt(std::pair<int, int> rowAndColumnIndexes, const ChessPieceBuilder &chessPieceBuilder, ChessPieceColor chessPieceColor) // added this function for testing, might get depcrecated later
{
    if (!isRowAndColumnIndexesValid(*this, rowAndColumnIndexes))
        return nullptr;

    const int rowIndex = rowAndColumnIndexes.first;
    const int columnIndex = rowAndColumnIndexes.second;

    m_board[rowIndex][columnIndex] = chessPieceBuilder.create(chessPieceColor);

    auto *insertedChessPiece = getChessPieceAt(rowAndColumnIndexes);

    if (insertedChessPiece && insertedChessPiece->getName() == ChessPieceName::King)
    {
        if (chessPieceColor == ChessPieceColor::Black)
            m_blackKingCurrentPosition = rowAndColumnIndexes;

        else
            m_whiteKingCurrentPosition = rowAndColumnIndexes;
    }

    return insertedChessPiece;
}

const ChessPiece *ChessBoard::getChessPieceAt(std::pair<int, int> rowAndColumnIndexes) const
{
    const int rowIndex = rowAndColumnIndexes.first;
    const int columnIndex = rowAndColumnIndexes.second;

    if (!isRowAndColumnIndexesValid(*this, rowAndColumnIndexes))
        return nullptr;

    return m_board[rowIndex][columnIndex].get();
}

static std::pair<int, int> getNextRowAndColumn(std::pair<int, int> currentPosition, DirectionInWhitePerspective direction)
{
    using Direction = DirectionInWhitePerspective;

    const int rowIndex = currentPosition.first;
    const int columnIndex = currentPosition.second;

    switch (direction)
    {
    case Direction::Forward:
        return {rowIndex - 1, columnIndex};
    case Direction::UpperRight:
        return {rowIndex - 1, columnIndex + 1};
    case Direction::Right:
        return {rowIndex, columnIndex + 1};
    case Direction::LowerRight:
        return {rowIndex + 1, columnIndex + 1};
    case Direction::Backward:
        return {rowIndex + 1, columnIndex};
    case Direction::LowerLeft:
        return {rowIndex + 1, columnIndex - 1};
    case Direction::Left:
        return {rowIndex, columnIndex - 1};
    case Direction::UpperLeft:
        return {rowIndex - 1, columnIndex - 1};
    }
}

// I can scan in a given direction if there is a chess piece, next is to use it to see if a chess piece can see my king so I can put it under check
// and of course remains the pawn and knight. a good Idea is to create 2 more static functions for them like this one.
// this function can be used to check if a piece is pinned as well

static ChessPiece *scanInGivenDirectionForChessPiece(const ChessBoard &chessBoard, std::pair<unsigned, unsigned> startingRowAndColumn, DirectionInWhitePerspective direction)
{
    const auto numberOfRows = chessBoard.getNumberOfRows();
    const auto numberOfColumns = chessBoard.getNumberOfColumns();

    auto currentRowAndIndex = getNextRowAndColumn(startingRowAndColumn, direction);

    while (isRowAndColumnIndexesValid(chessBoard, currentRowAndIndex))
    {
        const auto rowIndex = currentRowAndIndex.first;
        const auto columnIndex = currentRowAndIndex.second;

        if (chessBoard.getBoard()[rowIndex][columnIndex])
            return chessBoard.getBoard()[rowIndex][columnIndex].get();

        currentRowAndIndex = getNextRowAndColumn(currentRowAndIndex, direction);
    }

    return nullptr;
}

// in the case of the knight and pawn, this function might add to the vector some invalid squares, so it is mandatory to check if any square of the vector
// returned by this function valid or not before using it. if and when this behavior is fixed, this comment shall be removed.
static std::vector<std::pair<int, int>> getVisibleAttackedSquares(const ChessBoard &chessBoard, const std::pair<int, int> &rowAndColumnIndexes, ChessPieceVision chessPieceVision, ChessPieceColor chessPieceColor)
{
    using Direction = DirectionInWhitePerspective;

    std::vector<std::pair<int, int>> visibleSquares;

    if (!isRowAndColumnIndexesValid(chessBoard, rowAndColumnIndexes))
        return visibleSquares;

    const int rowIndex = rowAndColumnIndexes.first;
    const int columnIndex = rowAndColumnIndexes.second;

    switch (chessPieceVision)
    {
    case ChessPieceVision::Front:
    {
        visibleSquares.reserve(2);

        if (chessPieceColor == ChessPieceColor::White)
        {
            visibleSquares.emplace_back(getNextRowAndColumn(rowAndColumnIndexes, Direction::UpperLeft));
            visibleSquares.emplace_back(getNextRowAndColumn(rowAndColumnIndexes, Direction::UpperRight));

            break;
        }

        visibleSquares.emplace_back(getNextRowAndColumn(rowAndColumnIndexes, Direction::LowerLeft));
        visibleSquares.emplace_back(getNextRowAndColumn(rowAndColumnIndexes, Direction::LowerRight));

        break;
    }

    case ChessPieceVision::LShape:
    {
        visibleSquares.reserve(8);

        visibleSquares.emplace_back(getNextRowAndColumn(getNextRowAndColumn(rowAndColumnIndexes, Direction::UpperLeft), Direction::Forward));
        visibleSquares.emplace_back(getNextRowAndColumn(getNextRowAndColumn(rowAndColumnIndexes, Direction::UpperLeft), Direction::Left));

        visibleSquares.emplace_back(getNextRowAndColumn(getNextRowAndColumn(rowAndColumnIndexes, Direction::UpperRight), Direction::Forward));
        visibleSquares.emplace_back(getNextRowAndColumn(getNextRowAndColumn(rowAndColumnIndexes, Direction::UpperRight), Direction::Right));

        visibleSquares.emplace_back(getNextRowAndColumn(getNextRowAndColumn(rowAndColumnIndexes, Direction::LowerLeft), Direction::Backward));
        visibleSquares.emplace_back(getNextRowAndColumn(getNextRowAndColumn(rowAndColumnIndexes, Direction::LowerLeft), Direction::Left));

        visibleSquares.emplace_back(getNextRowAndColumn(getNextRowAndColumn(rowAndColumnIndexes, Direction::LowerRight), Direction::Backward));
        visibleSquares.emplace_back(getNextRowAndColumn(getNextRowAndColumn(rowAndColumnIndexes, Direction::LowerRight), Direction::Right));

        break;
    }

    case ChessPieceVision::Diagonal:
    {
        visibleSquares.reserve(13);
        Direction direction = Direction::UpperRight;
        bool scannedAllDirections = false;

        while (!scannedAllDirections)
        {
            if (direction == Direction::UpperLeft)
                scannedAllDirections = true;

            auto nextRowAndColumnIndexes = getNextRowAndColumn(rowAndColumnIndexes, direction);

            while (isRowAndColumnIndexesValid(chessBoard, nextRowAndColumnIndexes))
            {
                visibleSquares.emplace_back(nextRowAndColumnIndexes);

                if (chessBoard.getChessPieceAt(nextRowAndColumnIndexes))
                    break;

                nextRowAndColumnIndexes = getNextRowAndColumn(nextRowAndColumnIndexes, direction);
            }

            ++direction;
            ++direction;
        }

        break;
    }

    case ChessPieceVision::Straight:
    {
        visibleSquares.reserve(14);
        Direction direction = Direction::Forward;
        bool scannedAllDirections = false;

        while (!scannedAllDirections)
        {
            if (direction == Direction::Left)
                scannedAllDirections = true;

            auto nextRowAndColumnIndexes = getNextRowAndColumn(rowAndColumnIndexes, direction);

            while (isRowAndColumnIndexesValid(chessBoard, nextRowAndColumnIndexes))
            {
                visibleSquares.emplace_back(nextRowAndColumnIndexes);

                if (chessBoard.getChessPieceAt(nextRowAndColumnIndexes))
                    break;

                nextRowAndColumnIndexes = getNextRowAndColumn(nextRowAndColumnIndexes, direction);
            }

            ++direction;
            ++direction;
        }

        break;
    }

    case ChessPieceVision::AllDirections:
    {
        visibleSquares.reserve(24);
        Direction direction = Direction::Forward;
        bool scannedAllDirections = false;

        while (!scannedAllDirections)
        {
            if (direction == Direction::UpperLeft)
                scannedAllDirections = true;

            auto nextRowAndColumnIndexes = getNextRowAndColumn(rowAndColumnIndexes, direction);

            while (isRowAndColumnIndexesValid(chessBoard, nextRowAndColumnIndexes))
            {
                visibleSquares.emplace_back(nextRowAndColumnIndexes);

                if (chessBoard.getChessPieceAt(nextRowAndColumnIndexes))
                    break;

                nextRowAndColumnIndexes = getNextRowAndColumn(nextRowAndColumnIndexes, direction);
            }

            ++direction;
        }

        break;
    }
    }

    return visibleSquares;
}

bool ChessBoard::isKingInCheck(ChessPieceColor chessPieceColor) const
{
    using Direction = DirectionInWhitePerspective;
    if (!isKingExists(chessPieceColor))
        return false;

    const auto kingRowAndColumnIndexes = chessPieceColor == ChessPieceColor::White ? m_whiteKingCurrentPosition : m_blackKingCurrentPosition;
    const auto *king = m_board[kingRowAndColumnIndexes.first][kingRowAndColumnIndexes.second].get();

    Direction direction = Direction::Forward;

    for (bool scannedAllDirections = false; !scannedAllDirections; ++direction)
    {
        if (direction == Direction::UpperLeft)
            scannedAllDirections = true;

        const auto *chessPiece = scanInGivenDirectionForChessPiece(*this, kingRowAndColumnIndexes, direction);

        if (!chessPiece)
            continue;

        auto chessPieceVision = chessPiece->getVision();

        if (chessPiece->getColor() != king->getColor() && (chessPieceVision == ChessPieceVision::AllDirections || chessPieceVision == getVisionRelevantToDirection(direction)))
            return true;
    }

    // in order to check if the king is attacked by a pawn or a knight, what I decided to do is for the king to mimic the vision of these pieces,
    // so a king will have the vision of the pawn with same color, and of the knight, will get the visible squares, and then check if there is an attacking
    // piece these squares that has the corresponding vision

    auto squares = getVisibleAttackedSquares(*this, kingRowAndColumnIndexes, ChessPieceVision::Front, king->getColor());

    for (const auto &square : squares)
    {
        const auto *chessPiece = this->getChessPieceAt(square);

        if (chessPiece && chessPiece->getVision() == ChessPieceVision::Front && chessPiece->getColor() != king->getColor())
            return true;
    }

    squares = getVisibleAttackedSquares(*this, kingRowAndColumnIndexes, ChessPieceVision::LShape, king->getColor());

    for (const auto &square : squares)
    {
        const auto *chessPiece = this->getChessPieceAt(square);

        if (chessPiece && chessPiece->getVision() == ChessPieceVision::LShape && chessPiece->getColor() != king->getColor())
            return true;
    }

    return false;
}