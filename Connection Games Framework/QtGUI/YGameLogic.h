#pragma once
#include "YBoard.h"
#include "GameLogic.h"
#include "Cells.cpp"


template <typename T>
class YGameLogic : public GameLogic<T>, public YBoard<T>
{
};

template <>
class YGameLogic<Cells::Cell_Y> : public GameLogic<Cells::Cell_Y>, public YBoard<Cells::Cell_Y>
{
public:
    uint16_t DFS(const uint16_t&, const uint16_t&);
    bool VerifyRules(const uint16_t&, const uint16_t&)override;
    void EdgesCounter(const uint16_t& row, const uint16_t& column, uint16_t& edgesCount, std::array<bool,3>&);
};
