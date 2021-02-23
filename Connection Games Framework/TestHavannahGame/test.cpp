#include "pch.h"
#include"../Connection Games Framework/HavannahGameLogic.h"
#include"../Connection Games Framework/HavannahGameLogic.cpp"
TEST(TestCaseName, TestName) 
{

	HavannahGameLogic<Cells::Cell_Havannah> game;
	game.InitBoard();
	for (uint16_t index1 = 0; index1 < 19; index1++)
	{
			for (uint16_t index2 = 0; index2 < game.GetBoard()[index1].size(); index2++)
			{
				EXPECT_EQ(game.GetBoard()[index1][index2].color, Player::Color::white);
				EXPECT_EQ(game.GetBoard()[index1][index2].visited, 0);
			

				if (index1 != 0 && index1 != 18)
				{
					if (index2 != 0 && index2 != game.GetBoard()[index1].size() - 1)
					{

						EXPECT_EQ(game.GetBoard()[index1][index2].type, Cells::Type::none);
					}
				}
			}
		
	}

	//corners
	EXPECT_EQ(game.GetBoard()[0][0].type, Cells::Type::top_left_corner);
	EXPECT_EQ(game.GetBoard()[0][9].type, Cells::Type::top_right_corner);
	EXPECT_EQ(game.GetBoard()[9][0].type, Cells::Type::left_corner);
	EXPECT_EQ(game.GetBoard()[9][18].type, Cells::Type::right_corner);
	EXPECT_EQ(game.GetBoard()[18][0].type, Cells::Type::bottom_left_corner);
	EXPECT_EQ(game.GetBoard()[18][9].type, Cells::Type::bottom_right_corner);


	//edges
	for (uint16_t index = 1; index < 9; index++) //margine Nord
	{
		EXPECT_EQ(game.GetBoard()[0][index].type , Cells::Type::top_edge);
	}

	for (uint16_t index = 1; index <9; index++) //margine Nord-Vest
	{
		EXPECT_EQ(game.GetBoard()[index][0].type , Cells::Type::top_left_edge);
	}

	for (uint16_t index = 10; index < 18; index++) //margine Sud-Vest
	{
		EXPECT_EQ(game.GetBoard()[index][0].type , Cells::Type::bottom_left_edge);
	}

	for (uint16_t index = 1; index <9; index++) //margine Sud
	{
		EXPECT_EQ(game.GetBoard()[18][index].type , Cells::Type::bottom_edge);
	}

	for (uint16_t index =10; index < 18; index++) //margine Sud-Est
	{
		EXPECT_EQ(game.GetBoard()[index][game.GetBoard()[index].size() - 1].type , Cells::Type::bottom_right_edge);
	}

	for (uint16_t index = 1; index < 9; index++) //margine Nord-Est
	{
		EXPECT_EQ(game.GetBoard()[index][game.GetBoard()[index].size() - 1].type , Cells::Type::top_right_edge);
	}

	EXPECT_EQ(game.MoveIsValid(-1, -1), false);
	EXPECT_EQ(game.MoveIsValid(0, 10), false);
	EXPECT_EQ(game.MoveIsValid(1, 10), true);
	EXPECT_EQ(game.MoveIsValid(7, 5), true);
	EXPECT_EQ(game.MoveIsValid(9, 19), false);
	EXPECT_EQ(game.MoveIsValid(19, 11), false);
	EXPECT_EQ(game.MoveIsValid(12, 14), true);
	EXPECT_EQ(game.MoveIsValid(2, 3), true);

	game.GetPlayer1().SetName("Vlad");
	EXPECT_EQ(game.GetPlayer1().GetName(), "Vlad");
	game.GetPlayer1().SetColor(Player::Color::blue);
	EXPECT_EQ(game.GetPlayer1().GetColor(), Player::Color::blue);

	game.GetPlayer2().SetName("Andrei");
	EXPECT_EQ(game.GetPlayer2().GetName(), "Andrei");
	game.GetPlayer2().SetColor(Player::Color::orange);
	EXPECT_EQ(game.GetPlayer2().GetColor(), Player::Color::orange);

	game.PlayerTurn(5, 4, game.GetPlayer1());
	EXPECT_EQ(game.GetBoard()[5][4].color, Player::Color::blue);
	game.RuleOfPie(5, 4);
	EXPECT_EQ(game.GetBoard()[5][4].color, Player::Color::orange);

	EXPECT_NO_FATAL_FAILURE(game.Reset());
	game.GetBoard()[1][2].visited = true;
	game.Reset();
	EXPECT_FALSE(game.GetBoard()[1][2].visited == true);
	EXPECT_EQ(game.GetBoard()[1][2].visited, false);

	EXPECT_NO_FATAL_FAILURE(game.ResetRing());
	game.GetBoard()[1][2].visited = 2;
	game.ResetRing();
	EXPECT_FALSE(game.GetBoard()[1][2].visited == 2);
	EXPECT_EQ(game.GetBoard()[1][2].visited, 0);

	game.PlayerTurn(3,3, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(3,3) == true);
	game.PlayerTurn(3,4, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(3,4) == true);
	game.PlayerTurn(4,3, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(4,3) == true);
	game.PlayerTurn(4,5, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(4,5) == true);
	game.PlayerTurn(5,4, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(5,4) == true);
	game.PlayerTurn(5,6, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(5,6) == true);
	game.PlayerTurn(6, 4, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(6,4) == true);
	game.PlayerTurn(6,7, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(6,7) == true);
	game.PlayerTurn(7,5, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(7,5) == true);
	game.PlayerTurn(7,6, game.GetPlayer1());
	EXPECT_FALSE(game.VerifyRules(7,6) == true);
	game.PlayerTurn(7,7, game.GetPlayer1());
	EXPECT_EQ(game.VerifyRules(7,7), true);
	EXPECT_NO_FATAL_FAILURE(game.VerifyRules(7,7));


}


