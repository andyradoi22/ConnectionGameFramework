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
    HavannahBoard() { m_cells = 10; }
    ~HavannahBoard()override = default;
    void InitBoard()override;
};
