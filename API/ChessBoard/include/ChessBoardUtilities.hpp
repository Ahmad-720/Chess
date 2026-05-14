#pragma once

#include "fwd.hpp"

std::pair<unsigned, unsigned> getRowAndColumnFromSquare(Square square);
Square getSquareFromRowAndColumn(unsigned rowIndex, unsigned columnIndex);

bool operator==(const Square &lhs, const Square &rhs);