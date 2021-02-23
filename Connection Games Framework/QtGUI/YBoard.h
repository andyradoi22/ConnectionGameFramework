#pragma once
#include <stack>
#include <tuple>
#include "Board.h"
#include"Cells.cpp"

template <typename T>
class YBoard :public  virtual Board<T>
{
};

template <>
class YBoard<Cells::Cell_Y> : public virtual Board<Cells::Cell_Y>
{
private:

public:
    YBoard() { m_cells = 13; }
    ~YBoard() override = default;
    YBoard(uint16_t nrc) :Board<Cells::Cell_Y>(nrc) {}
    void InitBoard() override;
};
