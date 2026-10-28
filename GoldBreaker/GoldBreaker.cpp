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