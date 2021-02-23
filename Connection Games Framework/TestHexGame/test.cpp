#include "pch.h"
#include"../Connection Games Framework/HexGameLogic.h"
#include"../Connection Games Framework/HexGameLogic.cpp"
TEST(TestCaseName, TestName)
{
	HexGameLogic<Cells::Cell_Hex> game;
	game.InitBoard();
	for (int index1 = 0; index1 < 11; index1++)
	{
		for (int index2 = 0; index2 < 11; index2++)
		{
			EXPECT_EQ(game.GetBoard()[index1][index2].color, Player::Color::white);
			EXPECT_EQ(game.GetBoard()[index1][index2].visited, false);
			if (index1 == 0)
				EXPECT_EQ(game.GetBoard()[index1][index2].cardinals.N, true);

			if (index1 == 10)

				EXPECT_EQ(game.GetBoard()[index1][index2].cardinals.S, true);
			if (index2 == 0)

				EXPECT_EQ(game.GetBoard()[index1][index2].cardinals.V, true);
			if (index2 == 10)
				EXPECT_EQ(game.GetBoard()[index1][index2].cardinals.E, true);
		}
	}
	EXPECT_EQ(game.MoveIsValid(-1, -1), false);
	EXPECT_EQ(game.MoveIsValid(0, 11), false);
	EXPECT_EQ(game.MoveIsValid(1, 10), true);
	EXPECT_EQ(game.MoveIsValid(7, 5), true);

	game.GetPlayer1().SetName("Ioana");
	EXPECT_EQ(game.GetPlayer1().GetName(), "Ioana");
	game.GetPlayer1().SetColor(Player::Color::green);
	EXPECT_EQ(game.GetPlayer1().GetColor(), Player::Color::green);

	game.GetPlayer2().SetName("Ale");
	EXPECT_EQ(game.GetPlayer2().GetName(), "Ale");
	game.GetPlayer2().SetColor(Player::Color::black);
	EXPECT_EQ(game.GetPlayer2().GetColor(), Player::Color::black);

	game.PlayerTurn(5, 4, game.GetPlayer1());
	EXPECT_EQ(game.GetBoard()[5][4].color, Player::Color::green);
	game.RuleOfPie(5, 4);
	EXPECT_EQ(game.GetBoard()[5][4].color, Player::Color::black);

	EXPECT_NO_FATAL_FAILURE(game.Reset());
	game.GetBoard()[9][2].visited = true;
	game.Reset();
	EXPECT_FALSE(game.GetBoard()[9][2].visited == true);
	EXPECT_EQ(game.GetBoard()[9][2].visited, false);


	game.PlayerTurn(5,0, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(5, 0) == true);
	game.PlayerTurn(5,1, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(5, 1) == true);
	game.PlayerTurn(6,1, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(6,1) == true);
	game.PlayerTurn(7, 1, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(7,1) == true);
	game.PlayerTurn(7,2, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(7,2) == true);
	game.PlayerTurn(6,3, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(6,3) == true);
	game.PlayerTurn(5,4, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(5, 4) == true);
	game.PlayerTurn(4,5, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(4,5) == true);
	game.PlayerTurn(3,6, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(3,6) == true);
	game.PlayerTurn(3,7, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(3,7) == true);
	game.PlayerTurn(3,8, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(3,8) == true);
	game.PlayerTurn(4,8, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(4,8) == true);
	game.PlayerTurn(5,8, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(5, 8) == true);
	game.PlayerTurn(6,8, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(6,8) == true);
	game.PlayerTurn(6,9, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(6,9) == true);
	game.PlayerTurn(5,10, game.GetPlayer1());
	EXPECT_EQ(game.VerifyRules(5,10), true);
	EXPECT_NO_FATAL_FAILURE(game.VerifyRules(5,10));

}