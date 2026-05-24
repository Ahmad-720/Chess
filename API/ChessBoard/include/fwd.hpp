#pragma once

#include <utility>

class ChessBoard;
using Square = std::pair<char, unsigned>;

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
