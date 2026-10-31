#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
#include <windows.h>

#include "Tiles.h"
#include "Map.h"
#include "Player.h"

void DisplayMap(Map map, Player player)
{

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int y = 0; y < 10; ++y) {
		for (int x = 0; x < 7; ++x) {

			int index = GetCell(x, y);

			if (player.IsHere(x, y)) // Detects if the player is here
			{
				player.ShowName();
			}
			else {
				SetConsoleTextAttribute(hConsole, GetTileFromPos(x, y, map).color);
				std::cout << GetTileFromPos(x, y, map).name_Display << ' '; // La ligne ultime ?
			}

		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main()
{
	srand(time(0));

    Player player;

	Map map;
	
	map = CreateMap();



    DisplayMap(map, player);
    player.DisplayStats();

	while (true)
	{
		player.MovePlayer(map);
		system("cls");
		DisplayMap(map, player);
		player.DisplayStats();
	}




    return 0;
}