#pragma once
#include"Board.h"
#include"Cells.cpp"
#include<iostream>

template <typename T>
class HavannahBoard :virtual public Board<T>
{
};

template <>
class HavannahBoard<Cells::Cell_Havannah> : virtual public Board<Cells::Cell_Havannah>
{
public:
	HavannahBoard() { m_cells = 10; };
	HavannahBoard(const HavannahBoard&) = default;
	~HavannahBoard() = default;
	void InitBoard()override;
	
};

inline void HavannahBoard<Cells::Cell_Havannah>::InitBoard()
{
	for (uint16_t index1 = 0; index1 < 2 * m_cells - 1; index1++)
	{
		std::vector<Cells::Cell_Havannah> aux;
		Cells::Cell_Havannah obj;
		obj.visited = 0;
		obj.color = Player::Color::white;
		obj.type = Cells::Type::none;
		if (index1 < m_cells)
		{
			for (uint16_t index2 = 0; index2 < index1 + m_cells; index2++)
			{
				aux.push_back(obj);
			}
		}
		else
		{
			for (uint16_t index2 = 0; index2 < 3 * m_cells - index1 - 2; index2++)
			{
				aux.push_back(obj);
			}
		}
		m_board.push_back(aux);
	}

	//corners
	m_board[0][0].type = Cells::Type::top_left_corner;
	m_board[0][m_board[0].size() - 1].type = Cells::Type::top_right_corner;
	m_board[m_board[0].size() - 1][0].type = Cells::Type::left_corner;
	m_board[m_cells - 1][2 * (m_board[0].size() - 1)].type = Cells::Type::right_corner;
	m_board[m_board.size() - 1][0].type = Cells::Type::bottom_left_corner;
	m_board[m_board.size() - 1][m_board[0].size() - 1].type = Cells::Type::bottom_right_corner;

	//edges
	for (uint16_t index = 1; index < m_cells - 1; index++) //margine Nord
	{
		m_board[0][index].type = Cells::Type::top_edge;
	}

	for (uint16_t index = 1; index < m_cells - 1; index++) //margine Nord-Vest
	{
		m_board[index][0].type = Cells::Type::top_left_edge;
	}

	for (uint16_t index = m_cells; index < m_board.size() - 1; index++) //margine Sud-Vest
	{
		m_board[index][0].type = Cells::Type::bottom_left_edge;
	}

	for (uint16_t index = 1; index < m_cells - 1; index++) //margine Sud
	{
		m_board[m_board.size() - 1][index].type = Cells::Type::bottom_edge;
	}

	for (uint16_t index = m_cells; index < m_board.size() - 1; index++) //margine Sud-Est
	{
		m_board[index][m_board[index].size() - 1].type = Cells::Type::bottom_right_edge;
	}

	for (uint16_t index = 1; index < m_cells - 1; index++) //margine Nord-Est
	{
		m_board[index][m_board[index].size() - 1].type = Cells::Type::top_right_edge;
	}
}
