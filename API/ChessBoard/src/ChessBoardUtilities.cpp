#include "../include/ChessBoardUtilities.hpp"

#include <stdexcept>

std::pair<unsigned, unsigned> getRowAndColumnFromSquare(Square square)
{
    const auto column = square.first;
    const auto row = square.second;

    if ((!std::islower(column) && !std::isupper(column)) || row == 0)
        throw std::invalid_argument("invalid square");

    unsigned columnIndex = std::isupper(column) ? std::tolower(column) : column;
    unsigned rowIndex = 8 - row;

    columnIndex -= 'a';

    return {columnIndex, rowIndex};
}