#include "ConnectionGames.h"
#include <string>

void ConnectionGames::Run()
{
	uint16_t opt;
	std::cout << "Apasati:" << std::endl << "  0 pentru Hex" << std::endl << "  1 pentru Havannah"
		<< std::endl << "  2 pentru Y" << std::endl << "  9 pentru EXIT" << std::endl;
	std::cin >> opt;

	while (opt != 9)
	{
		switch (opt)
		{
		case 0:
		{
			HexGameLogic<Cells::Cell_Hex> game;
			RunGame(game);
			break;
		}
		case 1:
		{
			HavannahGameLogic<Cells::Cell_Havannah> game;
			RunGame(game);
			break;
		}
		case 2:
		{
			YGameLogic<Cells::Cell_Y> game;
			RunGame(game);
			break;
		}
		case 9: { break; }
		default:
		{
			std::cout << "Optiunea introdusa nu este valida, va rugam introduceti alta: ";
			std::cin >> opt;
		}
		std::cout << std::endl << "Doriti sa reicepeti?(D/N)";
		std::string raspuns;
		std::cin >> raspuns;
		if (raspuns == "D")
		{
			std::cout << "Apasati:" << std::endl << "  0 pentru Hex" << std::endl << "  1 pentru Havannah"
				<< std::endl << "  2 pentru Y" << std::endl << "  9 pentru EXIT" << std::endl;
			std::cin >> opt;
		}
		}
	}
}