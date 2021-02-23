#pragma once
#include<iostream>
#include<vector>
#include<array>
#include"Player.h"
#include<utility>

template <typename T>
class Board
{
public:
	std::vector<std::vector<T>> m_board;
	uint16_t m_cells;
	Player player1, player2;

public:
	Board() = default;
	Board(const Board&) = default;
	virtual ~Board() = default;
	Board(const uint16_t);
	virtual void InitBoard() {};
	uint16_t Getm_Cells()const { return m_cells; };
	std::vector < std::vector <T>>& GetBoard() { return m_board; };
	Player& GetPlayer1() { return player1; };
	Player& GetPlayer2() { return player2; };
};
