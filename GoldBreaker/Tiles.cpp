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


Tile GetTileFromPos(int x, int y, Map level)
{
	int cell_pos = GetCell(x, y);
	int cell_id = level.data[cell_pos];
	Tile current_tile = AllTiles[cell_id];
	return current_tile;

}

bool IsBlockHere(int x, int y, Map level)
{
	return GetTileFromPos(x, y, level).name != ' ';
}