#pragma once
#include"Board.h"
#include<iostream>
#include"Cells.cpp"
#include<windows.h>
template <typename T>

class GameLogic :virtual public Board<T>
{
};
template <>
class GameLogic<Cells::Cell_Y> :virtual public Board<Cells::Cell_Y>
{
public:
	bool MoveIsValid(const uint16_t& row, const uint16_t& column)
	{
		if ((row >= 0 && row < m_board.size()) && (column >= 0 && column < m_board[row].size()))
			return true;

		return false;
	};
	void RuleOfPie(const uint16_t& row, const uint16_t& column) { m_board[row][column].color = player2.GetColor(); };
	void PlayerTurn(const uint16_t& row, const uint16_t& column, Player& player)
	{
		if (MoveIsValid(row, column))
		{
			m_board[row][column].color = player.GetColor();
		}
	};
	void Reset()
	{
		for (auto& vector : m_board)
			for (auto& cell : vector)
			{
				cell.visited = false;
			}
	};
	virtual bool VerifyRules(const uint16_t&, const uint16_t&) { return false; };

	void Display()
	{
		std::cout << std::endl;
		uint16_t size = m_board.size();
		for (int16_t index = 0; index < size; index++)
		{
			for (uint16_t aux = 0; aux <= (size - index) / 2 + (size - index) % 2 - 1; aux++)
			{
				if (index % 2 == 0 && index > 4)
				{
					std::cout << "       ";
				}
				else
					if (index == 0 || index == 2)
					{
						std::cout << "      ";
					}
					else
						if (index == 1 || index == 3)
						{
							std::cout << "      ";
						}
						else
							if (index == 4)
							{
								std::cout << "       ";
							}
							else
							{
								std::cout << "      ";
							}
			}

			uint16_t size_row = m_board[index].size();
			for (int16_t contor = 0; contor < size_row; contor++)
			{
				std::cout << m_board[index][contor].color;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				std::cout << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};

template <>
class GameLogic<Cells::Cell_Havannah> :virtual public Board<Cells::Cell_Havannah>
{
public:
	bool MoveIsValid(const uint16_t& row, const uint16_t& column)
	{
		if ((row >= 0 && row < m_board.size()) && (column >= 0 && column < m_board[row].size()))
			return true;

		return false;
	};
	void RuleOfPie(const uint16_t& row, const uint16_t& column) { m_board[row][column].color = player2.GetColor(); };
	void PlayerTurn(const uint16_t& row, const uint16_t& column, Player& player)
	{
		if (MoveIsValid(row, column))
		{
			m_board[row][column].color = player.GetColor();
		}
	};
	void Reset()
	{
		for (auto& vector : m_board)
			for (auto& cell : vector)
			{
				cell.visited = false;
			}
	};
	virtual bool VerifyRules(const uint16_t&, const uint16_t&) { return false; };
	void Display()
	{
		std::cout << std::endl;
		uint16_t size = m_board.size();
		for (int16_t index = 0; index < size; index++)
		{
			if (index < size / 2)
				for (uint16_t aux = 0; aux <= m_cells - index; aux++)
				{
					std::cout << "  ";
				}
			else if (index > size / 2)
				for (uint16_t aux = 0; aux <= index - m_cells; aux++)
				{
					std::cout << "   ";
				}

			uint16_t size_row = m_board[index].size();
			for (int16_t contor = 0; contor < size_row; contor++)
			{
				std::cout << m_board[index][contor].color;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				std::cout << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};

template <>
class GameLogic<Cells::Cell_Hex> :virtual public Board<Cells::Cell_Hex>
{
public:
	bool MoveIsValid(const uint16_t& row, const uint16_t& column)
	{
		if ((row >= 0 && row < m_board.size()) && (column >= 0 && column < m_board[row].size()))
			return true;

		return false;
	};
	void RuleOfPie(const uint16_t& row, const uint16_t& column) { m_board[row][column].color = player2.GetColor(); };
	void PlayerTurn(const uint16_t& row, const uint16_t& column, Player& player)
	{
		if (MoveIsValid(row, column))
		{
			m_board[row][column].color = player.GetColor();
		}
	};
	void Reset()
	{
		for (auto& vector : m_board)
			for (auto& cell : vector)
			{
				cell.visited = false;
			}
	};	virtual bool VerifyRules(const uint16_t&, const uint16_t&) { return false; };

	void Display()
	{
		std::cout << std::endl;
		uint16_t size = m_board.size();
		for (int16_t index = 0; index < size; index++)
		{
			for (uint16_t aux = 0; aux <= index; aux++)
			{
				std::cout << "   ";
			}

			uint16_t size_row = m_board[index].size();
			for (int16_t contor = 0; contor < size_row; contor++)
			{
				std::cout << m_board[index][contor].color;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				std::cout << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};
