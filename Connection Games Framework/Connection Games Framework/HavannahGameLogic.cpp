#include "HavannahGameLogic.h"
#include <tuple>
#include <stack>

bool HavannahGameLogic<Cells::Cell_Havannah>::VerifyRules(const uint16_t& row, const uint16_t& column)
{
	std::tuple<int16_t, int16_t, bool> aux;

	if (m_board[row][column].color == player1.GetColor())
	{
		aux = DFS(row, column, player1);
		if (std::get<0>(aux) == 3 || std::get<1>(aux) == 2 || std::get<2>(aux) == true)
		{
			return true;
		}
	}
	else
	{
		if (m_board[row][column].color == player2.GetColor())
		{
			aux = DFS(row, column, player2);
			if (std::get<0>(aux) == 3 || std::get<1>(aux) == 2 || std::get<2>(aux) == true)
			{
				return true;
			}
		}
	}
	return false;
}

bool HavannahGameLogic<Cells::Cell_Havannah>::Ignore(const uint16_t& row, const uint16_t& column)
{
	int16_t x, y;
	std::vector<std::pair<int16_t, int16_t>> top_cell_neighbours = { {-1, -1}, {0, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0} };
	std::vector<std::pair<int16_t, int16_t>> bottom_cell_neighbours = { {-1, 0}, {0, -1}, {1, -1}, {1, 0}, {-1, 1}, {0, 1} };
	std::vector<std::pair<int16_t, int16_t>> mid_cell_neighbours = { {-1, -1}, {-1 , 0}, {0, 1}, {1, 0}, {1, -1}, {0, -1} };
	std::vector<std::pair<int16_t, int16_t>> colored_neighbours;

	if (row < m_cells - 1)
	{
		for (auto& coord : top_cell_neighbours)
		{
			x = row + coord.first;
			y = column + coord.second;
			if (MoveIsValid(x, y) && m_board[x][y].color == m_board[row][column].color)
			{
				colored_neighbours.push_back(std::make_pair(x, y));
			}
		}
		if (colored_neighbours.size() == 2)
		{
			x = colored_neighbours[0].first - colored_neighbours[1].first;
			y = colored_neighbours[0].second - colored_neighbours[1].second;
			if (std::find(top_cell_neighbours.begin(), top_cell_neighbours.end(), std::make_pair(x, y)) != top_cell_neighbours.end())
			{
				m_board[row][column].visited = 2;
				return true;
			}
		}
		if (colored_neighbours.size() == 1)
		{
			m_board[row][column].visited = 2;
		}
		return false;
	}
	if (row == m_cells - 1)
	{
		for (auto& coord : mid_cell_neighbours)
		{
			x = row + coord.first;
			y = column + coord.second;
			if (MoveIsValid(x, y) && m_board[x][y].color == m_board[row][column].color)
			{
				colored_neighbours.push_back(std::make_pair(x, y));
			}
		}
		if (colored_neighbours.size() == 2)
		{
			x = colored_neighbours[0].first - colored_neighbours[1].first;
			y = colored_neighbours[0].second - colored_neighbours[1].second;
			if (std::find(mid_cell_neighbours.begin(), mid_cell_neighbours.end(), std::make_pair(x, y)) != mid_cell_neighbours.end())
			{
				m_board[row][column].visited = 2;
				return true;
			}
		}
		if (colored_neighbours.size() == 1)
		{
			m_board[row][column].visited = 2;
		}
		return false;
	}
	if (row > m_cells - 1)
	{
		for (auto& coord : bottom_cell_neighbours)
		{
			x = row + coord.first;
			y = column + coord.second;
			if (MoveIsValid(x, y) && m_board[x][y].color == m_board[row][column].color)
			{
				colored_neighbours.push_back(std::make_pair(x, y));
			}
		}
		if (colored_neighbours.size() == 2)
		{
			x = colored_neighbours[0].first - colored_neighbours[1].first;
			y = colored_neighbours[0].second - colored_neighbours[1].second;
			if (std::find(bottom_cell_neighbours.begin(), bottom_cell_neighbours.end(), std::make_pair(x, y)) != bottom_cell_neighbours.end())
			{
				m_board[row][column].visited = 2;
				return true;
			}
		}
		if (colored_neighbours.size() == 1)
		{
			m_board[row][column].visited = 2;
		}
		return false;
	}
}

bool HavannahGameLogic<Cells::Cell_Havannah>::Stop(const uint16_t& row, const uint16_t& column)
{
	int16_t x, y;
	std::vector<std::pair<int16_t, int16_t>> top_cell_neighbours = { {-1, -1}, {0, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0} };
	std::vector<std::pair<int16_t, int16_t>> bottom_cell_neighbours = { {-1, 0}, {0, -1}, {1, -1}, {1, 0}, {-1, 1}, {0, 1} };
	std::vector<std::pair<int16_t, int16_t>> mid_cell_neighbours = { {-1, -1}, {-1 , 0}, {0, 1}, {1, 0}, {1, -1}, {0, -1} };
	std::vector<std::pair<int16_t, int16_t>> colored_neighbours;

	if (row < m_cells - 1)
		for (auto& coord : top_cell_neighbours)
		{
			x = row + coord.first;
			y = column + coord.second;
			if (MoveIsValid(x, y) && m_board[x][y].color == m_board[row][column].color)
			{
				colored_neighbours.push_back(std::make_pair(x, y));
			}
		}
	if (row == m_cells - 1)
		for (auto& coord : bottom_cell_neighbours)
		{
			x = row + coord.first;
			y = column + coord.second;
			if (MoveIsValid(x, y) && m_board[x][y].color == m_board[row][column].color)
			{
				colored_neighbours.push_back(std::make_pair(x, y));
			}
		}
	if (row > m_cells - 1)
		for (auto& coord : mid_cell_neighbours)
		{
			x = row + coord.first;
			y = column + coord.second;
			if (MoveIsValid(x, y) && m_board[x][y].color == m_board[row][column].color)
			{
				colored_neighbours.push_back(std::make_pair(x, y));
			}
		}

	for (auto index = 0; index < colored_neighbours.size(); index++)
	{
		for (auto contor = index + 1; contor < colored_neighbours.size(); contor++)
		{
			x = colored_neighbours[contor].first - colored_neighbours[index].first;
			y = colored_neighbours[contor].second - colored_neighbours[index].second;

			if (row < m_cells - 1)
				if (std::find(top_cell_neighbours.begin(), top_cell_neighbours.end(), std::make_pair(x, y)) == top_cell_neighbours.end())
				{
					if (m_board[colored_neighbours[contor].first][colored_neighbours[contor].second].visited == 1)
						if (m_board[colored_neighbours[index].first][colored_neighbours[index].second].visited == 1)
						{
							return true;
						}
				}

			if (row == m_cells - 1)
				if (std::find(mid_cell_neighbours.begin(), mid_cell_neighbours.end(), std::make_pair(x, y)) == mid_cell_neighbours.end())
				{
					if (m_board[colored_neighbours[contor].first][colored_neighbours[contor].second].visited == 1)
						if (m_board[colored_neighbours[index].first][colored_neighbours[index].second].visited == 1)
						{
							return true;
						}
				}

			if (row > m_cells - 1)
				if (std::find(bottom_cell_neighbours.begin(), bottom_cell_neighbours.end(), std::make_pair(x, y)) == bottom_cell_neighbours.end())
				{
					if (m_board[colored_neighbours[contor].first][colored_neighbours[contor].second].visited == 1)
						if (m_board[colored_neighbours[index].first][colored_neighbours[index].second].visited == 1)
						{
							return true;
						}
				}
		}
	}
	return false;
}

std::tuple<uint16_t, uint16_t, bool> HavannahGameLogic<Cells::Cell_Havannah>::DFS(const uint16_t& row, const uint16_t& column, Player& player)
{
	std::vector<std::pair<int16_t, int16_t>> top_cell_neighbours = { {-1, -1}, {0, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0} };
	std::vector<std::pair<int16_t, int16_t>> bottom_cell_neighbours = { {-1, 0}, {0, -1}, {1, -1}, {1, 0}, {-1, 1}, {0, 1} };
	std::vector<std::pair<int16_t, int16_t>> mid_cell_neighbours = { {-1, -1}, {-1 , 0}, {0, 1}, {1, 0}, {1, -1}, {0, -1} };

	std::stack<std::pair<int16_t, int16_t>> stack;
	std::array<bool, 6> visited_edges = { false,false,false,false,false,false };
	std::array<bool, 6> visited_corners = { false,false,false,false,false,false };
	uint16_t edges_count = 0, corners_count = 0;
	bool ring;
	bool sw;

	uint16_t contor = 0;
	do {
		ring = false;
		sw = false;
		if (contor == 0)
		{
			EdgesCounter(row, column, edges_count, visited_edges);
			CornersCounter(row, column, corners_count, visited_corners);
		}

		std::pair<int16_t, int16_t> current = std::make_pair(row, column);
		stack.push(current);
		while (!stack.empty())
		{
			current = stack.top();
			stack.pop();
			m_board[current.first][current.second].visited = 1;

			if (current.first < m_cells - 1)
			{
				for (auto& coord : top_cell_neighbours)
				{
					int16_t x, y;
					x = current.first + coord.first;
					y = current.second + coord.second;
					if (MoveIsValid(x, y) && m_board[row][column].color == m_board[x][y].color
						&& m_board[x][y].visited == 0)
					{
						m_board[x][y].visited = 1;
						stack.push(std::make_pair(x, y));

						sw = Ignore(x, y);
						ring = Stop(x, y);
						if (contor == 0)
						{
							EdgesCounter(x, y, edges_count, visited_edges);
							CornersCounter(x, y, corners_count, visited_corners);
						}
					}
				}
			}

			if (current.first == m_cells - 1)
			{
				for (auto& coord : mid_cell_neighbours)
				{
					int16_t x, y;
					x = current.first + coord.first;
					y = current.second + coord.second;
					if (MoveIsValid(x, y) && m_board[row][column].color == m_board[x][y].color
						&& m_board[x][y].visited == 0)
					{
						m_board[x][y].visited = 1;
						stack.push(std::make_pair(x, y));
						sw = Ignore(x, y);
						ring = Stop(x, y);
						if (contor == 0)
						{
							EdgesCounter(x, y, edges_count, visited_edges);
							CornersCounter(x, y, corners_count, visited_corners);
						}
					}
				}
			}
			if (current.first > m_cells - 1)
			{
				for (auto& coord : bottom_cell_neighbours)
				{
					int16_t x, y;
					x = current.first + coord.first;
					y = current.second + coord.second;
					if (MoveIsValid(x, y) && m_board[row][column].color == m_board[x][y].color
						&& m_board[x][y].visited == 0)
					{
						m_board[x][y].visited = 1;
						stack.push(std::make_pair(x, y));
						sw = Ignore(x, y);
						ring = Stop(x, y);
						if (contor == 0)
						{
							EdgesCounter(x, y, edges_count, visited_edges);
							CornersCounter(x, y, corners_count, visited_corners);
						}
					}
				}
			}
		}
		if (sw == true)
		{
			ResetRing();
		}
		contor++;
	} while (sw);
	Reset();
	return std::make_tuple(edges_count, corners_count, ring);
}

void HavannahGameLogic<Cells::Cell_Havannah>::ResetRing()
{
	for (auto& vector : m_board)
	{
		for (auto& cell : vector)
		{
			if (cell.visited == 2)
				cell.visited = 0;
		}
	}
}

void HavannahGameLogic<Cells::Cell_Havannah>::EdgesCounter(const uint16_t& row, const uint16_t& column, uint16_t& edges_count, std::array<bool, 6>& visited_edges)
{
	if (m_board[row][column].type == Cells::Type::top_edge && visited_edges[0] == false)
	{
		edges_count++;
		visited_edges[0] = true;
	}
	else
		if (m_board[row][column].type == Cells::Type::top_right_edge && visited_edges[1] == false)
		{
			edges_count++;
			visited_edges[1] = true;
		}
		else
			if (m_board[row][column].type == Cells::Type::bottom_right_edge && visited_edges[2] == false)
			{
				edges_count++;
				visited_edges[2] = true;
			}
			else
				if (m_board[row][column].type == Cells::Type::bottom_edge && visited_edges[3] == false)
				{
					edges_count++;
					visited_edges[3] = true;
				}
				else
					if (m_board[row][column].type == Cells::Type::bottom_left_edge && visited_edges[4] == false)
					{
						edges_count++;
						visited_edges[4] = true;
					}
					else
						if (m_board[row][column].type == Cells::Type::top_left_edge && visited_edges[5] == false)
						{
							edges_count++;
							visited_edges[5] = true;
						}
}

void HavannahGameLogic<Cells::Cell_Havannah>::CornersCounter(const uint16_t& row, const uint16_t& column, uint16_t& corners_count, std::array<bool, 6>& visited_corners)
{
	if (m_board[row][column].type == Cells::Type::top_right_corner && visited_corners[0] == false)
	{
		corners_count++;
		visited_corners[0] = true;
	}
	else
		if (m_board[row][column].type == Cells::Type::right_corner && visited_corners[1] == false)
		{
			corners_count++;
			visited_corners[1] = true;
		}
		else
			if (m_board[row][column].type == Cells::Type::bottom_right_corner && visited_corners[2] == false)
			{
				corners_count++;
				visited_corners[2] = true;
			}
			else
				if (m_board[row][column].type == Cells::Type::bottom_left_corner && visited_corners[3] == false)
				{
					corners_count++;
					visited_corners[3] = true;
				}
				else
					if (m_board[row][column].type == Cells::Type::left_corner && visited_corners[4] == false)
					{
						corners_count++;
						visited_corners[4] = true;
					}
					else
						if (m_board[row][column].type == Cells::Type::top_left_corner && visited_corners[5] == false)
						{
							corners_count++;
							visited_corners[5] = true;
						}
}