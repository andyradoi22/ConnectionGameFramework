#pragma once
#include "HavannahBoard.h"
#include "GameLogic.h"
#include "Cells.cpp"

template <typename T>
class HavannahGameLogic : public GameLogic<T>, public HavannahBoard<T>
{
};

template <>
class HavannahGameLogic<Cells::Cell_Havannah> : public GameLogic<Cells::Cell_Havannah>, public HavannahBoard<Cells::Cell_Havannah>
{
public:
	bool VerifyRules(const uint16_t&, const uint16_t&)override;
	std::tuple<uint16_t, uint16_t, bool> DFS(const uint16_t&, const uint16_t&, Player&);
	void ResetRing();
	void EdgesCounter(const uint16_t&, const uint16_t&, uint16_t&, std::array<bool, 6>&);
	void CornersCounter(const uint16_t&, const uint16_t&, uint16_t&, std::array<bool, 6>&);
	bool Ignore(const uint16_t&, const uint16_t&);
	bool Stop(const uint16_t&, const uint16_t&);
};
