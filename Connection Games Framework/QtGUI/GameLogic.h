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
    bool MoveisValid(const uint16_t& row, const uint16_t& column)
    {
        if ((row >= 0 && row < m_board.size()) && (column >= 0 && column < m_board[row].size()))
            return true;

        return false;
    }
    void RuleOfPie(const uint16_t& row, const uint16_t& column) { m_board[row][column].color = player2.GetColor(); }
    void PlayerTurn(const uint16_t& row, const uint16_t& column, Player& player)
    {
        if (MoveisValid(row, column))
        {
            m_board[row][column].color = player.GetColor();
        }
    }
    void Reset()
    {
        for (auto& vector : m_board)
            for (auto& cell : vector)
            {
                cell.visited = false;
            }
    }
    virtual bool VerifyRules(const uint16_t&, const uint16_t&) { return false; }


};


template <>
class GameLogic<Cells::Cell_Havannah> :virtual public Board<Cells::Cell_Havannah>
{
public:
    bool MoveisValid(const uint16_t& row, const uint16_t& column)
    {
        if ((row >= 0 && row < m_board.size()) && (column >= 0 && column < m_board[row].size()))
            return true;

        return false;
    }
    void RuleOfPie(const uint16_t& row, const uint16_t& column) { m_board[row][column].color = player2.GetColor(); }
    void PlayerTurn(const uint16_t& row, const uint16_t& column, Player& player)
    {
        if (MoveisValid(row, column))
        {
            m_board[row][column].color = player.GetColor();
        }
    }
    void Reset()
    {
        for (auto& vector : m_board)
            for (auto& cell : vector)
            {
                cell.visited = false;
            }
    }
    virtual bool VerifyRules(const uint16_t&, const uint16_t&) { return false; }

};

template <>
class GameLogic<Cells::Cell_Hex> :virtual public Board<Cells::Cell_Hex>
{
public:
    bool MoveisValid(const uint16_t& row, const uint16_t& column)
    {
        if ((row >= 0 && row < m_board.size()) && (column >= 0 && column < m_board[row].size()))
            return true;

        return false;
    }
    void RuleOfPie(const uint16_t& row, const uint16_t& column) { m_board[row][column].color = player2.GetColor(); }
    void PlayerTurn(const uint16_t& row, const uint16_t& column, Player& player)
    {
        if (MoveisValid(row, column))
        {
            m_board[row][column].color = player.GetColor();
        }
    }
    void Reset()
    {
        for (auto& vector : m_board)
            for (auto& cell : vector)
            {
                cell.visited = false;
            }
    }
    virtual bool VerifyRules(const uint16_t&, const uint16_t&) { return false; }


};
