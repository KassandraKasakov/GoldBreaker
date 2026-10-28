#include <iostream>
#include <windows.h>

#include "Tiles.h"
#include "Map.h"
#include "Player.h"


int main()
{
    Player player;

	int map[70] = {
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0
	};

    DisplayMap(map, player);
    player.DisplayStats();

	while (true)
	{
		player.MovePlayer();
		system("cls");
		DisplayMap(map, player);
		player.DisplayStats();
	}




    return 0;
}