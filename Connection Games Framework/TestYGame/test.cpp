#include "pch.h"

#include"../Connection Games Framework/YGameLogic.h"
#include"../Connection Games Framework/YGameLogic.cpp"

TEST(TestCaseName, TestName) {
	YGameLogic<Cells::Cell_Y> game;
	game.InitBoard();
	for (int index1 = 0; index1 <= 13; index1++)
	{
		for (int index2 = 0; index2 <= index1; index2++)
		{
			EXPECT_EQ(game.GetBoard()[index1][index2].color, Player::Color::white);
			EXPECT_EQ(game.GetBoard()[index1][index2].visited, false);
			if (index2 == 0)
				EXPECT_EQ(game.GetBoard()[index1][index2].edge.left, true);
			if (index1 == index2)
				EXPECT_EQ(game.GetBoard()[index1][index2].edge.right, true);
			if (index1 == 13)
				EXPECT_EQ(game.GetBoard()[index1][index2].edge.bottom, true);
		}
	}

	EXPECT_EQ(game.MoveIsValid(-1, -1), false);
	EXPECT_EQ(game.MoveIsValid(0,3), false);
	EXPECT_EQ(game.MoveIsValid(0,0), true);
	EXPECT_EQ(game.MoveIsValid(13,5),true );

	game.GetPlayer1().SetName("Ana"); 
	EXPECT_EQ(game.GetPlayer1().GetName(), "Ana");
	game.GetPlayer1().SetColor(Player::Color::cream);
	EXPECT_EQ(game.GetPlayer1().GetColor(), Player::Color::cream);

	game.GetPlayer2().SetName("Maria");
	EXPECT_EQ(game.GetPlayer2().GetName(), "Maria");
	game.GetPlayer2().SetColor(Player::Color::pink);
	EXPECT_EQ(game.GetPlayer2().GetColor(), Player::Color::pink);

	game.PlayerTurn(5,4, game.GetPlayer1());
	EXPECT_EQ(game.GetBoard()[5][4].color, Player::Color::cream);
	game.RuleOfPie(5, 4);
	EXPECT_EQ(game.GetBoard()[5][4].color, Player::Color::pink);

	EXPECT_NO_FATAL_FAILURE(game.Reset());
	game.GetBoard()[6][2].visited = true;
	game.Reset();
	EXPECT_FALSE(game.GetBoard()[6][2].visited == true);
	EXPECT_EQ(game.GetBoard()[6][2].visited, false);

	game.PlayerTurn(13,1, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(13, 1) == true);
	game.PlayerTurn(12,0, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(12,0) == true);
	game.PlayerTurn(11, 0, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(11,0) == true);
	game.PlayerTurn(11, 1, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(11, 1) == true);
	game.PlayerTurn(10, 1, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(10, 1) == true);
	game.PlayerTurn(9, 1, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(9, 1) == true);
	game.PlayerTurn(8, 1, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(8, 1) == true);
	game.PlayerTurn(7, 1, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(7, 1) == true);
	game.PlayerTurn(6,0, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(6,0) == true);
	game.PlayerTurn(5,0, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(5,0) == true);
	game.PlayerTurn(5, 1, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(5,1) == true);
	game.PlayerTurn(5,2, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(5,2) == true);
	game.PlayerTurn(4,2, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(4,2) == true);
	game.PlayerTurn(3,2, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(3,2) == true);
	game.PlayerTurn(3,3, game.GetPlayer1());
	EXPECT_EQ(game.VerifyRules(3,3),true);
	EXPECT_NO_FATAL_FAILURE(game.VerifyRules(3,3));




}