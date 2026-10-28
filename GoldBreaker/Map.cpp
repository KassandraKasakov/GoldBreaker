#include <iostream>

#include "Tiles.h"
#include "Map.h"
#include "Player.h"




int GetCell(int x, int y)
{
	return y * 10 + x;
}

bool IsInMap(int x, int y)
{
	if (x < 0 or x > 6) {
		return false;
	}
	if (y < 0 or y > 9) {
		return false;
	}
	return true;
}


void DisplayMap(int map[70], Player player)
{
	for (int y = 0; y < 10; ++y) {
		for (int x = 0; x < 7; ++x) {

			int index = GetCell(x, y);

			if (player.IsHere(x, y)) // Detects if the player is here
			{
				player.ShowName();
			}
			else
			{
				std::cout << '.' << ' ';
			}

		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}