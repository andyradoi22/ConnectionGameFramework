#include "YGameLogic.h"

bool YGameLogic<Cells::Cell_Y>::VerifyRules(const uint16_t& row, const uint16_t& column)
{
    if (DFS(row, column) == 3)
    {
        return true;
    }
    return false;
}

uint16_t YGameLogic<Cells::Cell_Y>::DFS(const uint16_t& row, const uint16_t& column)
{
    std::vector<std::pair<int16_t, int16_t>> neighbours = { {0,-1},{-1 ,-1},{-1,0},{0,1},{1,1},{1,0} };
    std::stack<std::pair<int16_t, int16_t>> stack;
    uint16_t edge_count = 0;
    std::array<bool,3> visited_edges = { false,false,false };
    EdgesCounter(row, column, edge_count, visited_edges);

    std::pair<int16_t, int16_t> current = std::make_pair(row, column);
    stack.push(current);
    while (!stack.empty())
    {
        current = stack.top();
        stack.pop();
        m_board[current.first][current.second].visited = true;

        for (auto &coord : neighbours)
        {
            int16_t x, y;
            x = current.first + coord.first;
            y = current.second + coord.second;

            if (MoveisValid(x, y) && m_board[row][column].color == m_board[x][y].color
                && m_board[x][y].visited == false)
            {
                m_board[x][y].visited = true;
                stack.push(std::make_pair(x, y));
                EdgesCounter(x, y, edge_count, visited_edges);
            }
        }
    }
    Reset();
    return edge_count;
}

void YGameLogic<Cells::Cell_Y>::EdgesCounter(const uint16_t& row, const uint16_t& column, uint16_t& edges_count, std::array<bool,3> &visited_edges)
{
    if (m_board[row][column].edge.left && !visited_edges[0])
    {
        edges_count++;
        visited_edges[0] = true;
    }
    if (m_board[row][column].edge.right && !visited_edges[1])
    {
        edges_count++;
        visited_edges[1] = true;
    }
    if (m_board[row][column].edge.bottom && !visited_edges[2])
    {
        edges_count++;
        visited_edges[2] = true;
    }
}
