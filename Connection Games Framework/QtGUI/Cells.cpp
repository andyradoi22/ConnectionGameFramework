#pragma once
#include"Player.h"

namespace Cells {
    struct Cardinals
    {
        bool N = false, S = false, E = false, V = false;
    };

    struct Cell_Hex
    {
        Player::Color color;
        bool visited;
        Cardinals cardinals;
    };

    enum class Type
    {
        top_left_edge,
        top_right_edge,
        bottom_edge,
        top_edge,
        bottom_left_edge,
        bottom_right_edge,

        left_corner,
        right_corner,
        top_left_corner,
        top_right_corner,
        bottom_left_corner,
        bottom_right_corner,

        none
    };

    struct Cell_Havannah
    {
        Player::Color color;
        int visited;
        Type type;
    };
    struct Edge
    {
        bool left = false, right = false, bottom = false;
    };

    struct Cell_Y
    {
        Player::Color color;
        bool visited;
        Edge edge;
    };
}
