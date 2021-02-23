#pragma once
#include "YBoard.h"
#include "YGameLogic.h"
#include "HexBoard.h"
#include "HexGameLogic.h"
#include"HavannahBoard.h"
#include"HavannahGameLogic.h"
#include<unordered_map>
#include<Windows.h>

class ConnectionGames
{
public:
	void Run();
	template<typename T>
	void RunGame(T game);
	void DisplayColor();
	void ColorChoice(Player& player);
	std::unordered_map<Player::Color, bool>color_status;
};

inline void ConnectionGames::DisplayColor()
{
	std::cout << "Culorile disponibile sunt: " << std::endl;

	for (uint16_t index = 1; index <= 10; index++)
	{
		Player::Color aux = (Player::Color)index;
		std::cout << aux;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << " " << index << std::endl;
		color_status[aux] = false;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

inline void ConnectionGames::ColorChoice(Player& player)
{
	std::cout << "Introduceti numarul culorii dorite: ";
	uint16_t choice;
	std::cin >> choice;
	while (choice > 10 || choice < 1 || color_status[(Player::Color)choice] == true)
	{
		std::cout << "Numar invalid .Va rugam sa introduceti alt numar: ";
		std::cin >> choice;
	}
	player.SetColor((Player::Color)choice);
	color_status[(Player::Color)choice] = true;
}

template<typename T>
inline void ConnectionGames::RunGame(T game)
{
	DisplayColor();
	game.InitBoard();
	std::string name;
	std::cout << "Introduceti numele pentru player1: ";
	std::cin >> name;
	game.GetPlayer1().SetName(name);
	ColorChoice(game.GetPlayer1());

	std::cout << "Introduceti numele pentru player2: ";
	std::cin >> name;
	game.GetPlayer2().SetName(name);
	ColorChoice(game.GetPlayer2());

	std::reference_wrapper<Player> placing_player(game.GetPlayer1());
	std::reference_wrapper<Player> not_placing_player(game.GetPlayer2());

	uint16_t row, column;
	std::cout << placing_player.get() << "'s turn:  ";
	std::cin >> row >> column;
	while (!game.MoveIsValid(row, column) || game.GetBoard()[row][column].color != Player::Color::white)
	{
		std::cout << "Mutare invalida. Va rugam introduceti alta mutare: ";
		std::cin >> row >> column;
	}
	game.PlayerTurn(row, column, placing_player);
	game.Display();

	std::cout << "Doriti sa preluati mutarea primului jucator? ";

	bool alegere;
	std::cout << "Introduceti 1 pentru da sau 0 pentru nu: ";
	std::cin >> alegere;

	if (alegere == true)
	{
		game.RuleOfPie(row, column);
		game.Display();
	}
	else
	{
		std::swap(placing_player, not_placing_player);
	}

	while (!game.VerifyRules(row, column))
	{
		std::cout << placing_player.get() << "'s turn:  ";
		std::cin >> row >> column;
		while (!game.MoveIsValid(row, column) || game.GetBoard()[row][column].color != Player::Color::white)
		{
			std::cout << "Mutare invalida. Va rugam introduceti alta mutare: ";
			std::cin >> row >> column;
		}
		game.PlayerTurn(row, column, placing_player);
		game.Display();
		std::swap(placing_player, not_placing_player);
	}
	std::cout << std::endl << not_placing_player.get() << " este castigatorul!" << std::endl;
}
