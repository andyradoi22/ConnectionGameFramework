#include "HexGameLogic.h"
#include<stack>

bool HexGameLogic<Cells::Cell_Hex> ::VerifyRules(const uint16_t& row, const uint16_t& column)
{
	if (m_board[row][column].color == player1.GetColor())
	{
		if (DFS(row, column, player1) == 2)
		{
			return true;
		}
	}
	else
	{
		if (m_board[row][column].color == player2.GetColor())
		{
			if (DFS(row, column, player2) == 2)
			{
				return true;
			}
		}
	}
	return false;
}

uint16_t HexGameLogic<Cells::Cell_Hex> ::DFS(const uint16_t& row, const uint16_t& column, Player player)
{
	std::vector<std::pair<int16_t, int16_t>> neighbours = { {0,-1},{+1 ,-1},{-1,0},{0,1},{1,1},{1,0} };
	std::stack<std::pair<int16_t, int16_t>> stack;
	uint16_t edges_NS_count = 0, edges_VE_count = 0;
	std::array<bool, 2> visited_NS = { false,false };
	std::array<bool, 2> visited_VE = { false,false };

	EdgesCounter(row, column, player, edges_NS_count, edges_VE_count, visited_NS, visited_VE);

	std::pair<int16_t, int16_t> current = std::make_pair(row, column);
	stack.push(current);

	while (!stack.empty())
	{
		current = stack.top();
		stack.pop();
		m_board[current.first][current.second].visited = true;

		for (auto& coord : neighbours)
		{
			int16_t x, y;
			x = current.first + coord.first;
			y = current.second + coord.second;
			if (MoveIsValid(x, y) && m_board[row][column].color == m_board[x][y].color
				&& m_board[x][y].visited == 0)
			{
				m_board[x][y].visited = true;
				stack.push(std::make_pair(x, y));
				EdgesCounter(x, y, player, edges_NS_count, edges_VE_count, visited_NS, visited_VE);
			}
		}
	}
	Reset();
	if (player.GetColor() == player2.GetColor())
	{
		return edges_NS_count;
	}
	else if (player.GetColor() == player1.GetColor())
	{
		return edges_VE_count;
	}
	return 0;
}

void HexGameLogic<Cells::Cell_Hex> ::EdgesCounter(const uint16_t& row, const uint16_t& column, Player& player, uint16_t& edges_NS_count, uint16_t& edges_VE_count,
	std::array<bool, 2>& visited_NS, std::array<bool, 2>& visited_VE)
{
	if (player.GetColor() == player1.GetColor())
	{
		//verif VE
		if (m_board[row][column].cardinals.V && visited_VE[0] == false)
		{
			edges_VE_count++;
			visited_VE[0] = true;
		}
		else
			if (m_board[row][column].cardinals.E && visited_VE[1] == false)
			{
				edges_VE_count++;
				visited_VE[1] = true;
			}
	}
	else if (player.GetColor() == player2.GetColor())
	{
		//verif NS
		if (m_board[row][column].cardinals.N && visited_NS[0] == false)
		{
			edges_NS_count++;
			visited_NS[0] = true;
		}
		else
			if (m_board[row][column].cardinals.S && visited_NS[1] == false)
			{
				edges_NS_count++;
				visited_NS[1] = true;
			}
	}
}