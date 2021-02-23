#pragma once
#include"Board.h"
#include"Cells.cpp"
#include<iostream>

template <typename T>
class HexBoard :virtual public Board<T>
{
};

template <>
class HexBoard<Cells::Cell_Hex> :virtual public Board<Cells::Cell_Hex>
{
public:
    HexBoard() { m_cells = 11; }
    ~HexBoard() = default;
    void InitBoard()override;
};

inline void HexBoard<Cells::Cell_Hex>::InitBoard()
{
    for (int index1 = 0; index1 < m_cells; index1++)
    {
        std::vector<Cells::Cell_Hex> aux;
        for (int index2 = 0; index2 < m_cells; index2++)
        {
            Cells::Cell_Hex obj;
            if (index1 == 0)
                obj.cardinals.N = true;
            if (index1 == m_cells - 1)
                obj.cardinals.S = true;
            if (index2 == 0)
                obj.cardinals.V = true;
            if (index2 == m_cells - 1)
                obj.cardinals.E = true;

            obj.visited = false;
            obj.color = Player::Color::white;

            aux.push_back(obj);
        }
        m_board.push_back(aux);
    }
}
