#pragma once
#include "HexBoard.h"
#include "GameLogic.h"
#include "Cells.cpp"

template <typename T>
class HexGameLogic : public GameLogic<T>, public HexBoard<T>
{
};

template <>
class HexGameLogic<Cells::Cell_Hex> : public GameLogic<Cells::Cell_Hex>, public HexBoard<Cells::Cell_Hex>
{
public:
    uint16_t DFS(const uint16_t&, const uint16_t&, Player);
    bool VerifyRules(const uint16_t&, const uint16_t&) override;
    void EdgesCounter(const uint16_t&, const uint16_t&, Player&, uint16_t&, uint16_t&, std::array<bool, 2>&, std::array<bool, 2>&);
};
