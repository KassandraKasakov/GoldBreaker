#include "Tiles.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
#include <windows.h>

#include "Map.h"
#include "Player.h"


std::vector<Tile> damagedTiles = {};



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

bool IsBlockWalkable(int x, int y, Map level)
{
	return GetTileFromPos(x, y, level).walkable != false;
}



int GetTileDamaged(int x, int y)
{
	for (int i = 0;i < damagedTiles.size();i++)
	{
		if (damagedTiles[i].x == x and damagedTiles[i].y == y)
		{
			return i;
		}
	}
	return -1;
}

void AddDamagedTile(int x, int y, Tile tile)
{
	damagedTiles.push_back(tile);
	damagedTiles.back().x = x;
	damagedTiles.back().y = y;
}

void DamageTile(int tile_id)
{
	damagedTiles[tile_id].durability -= 1;
}

void RemoveDamagedTile(int tile_id)
{
	damagedTiles[tile_id].durability -= 1;

	// Remove the tile if the durability is 0
	if (damagedTiles[tile_id].durability == 0)
	{
		RemoveDamagedTile(tile_id);
	}
}

void RemoveDamagedTile(int tile_id)
{
	damagedTiles.erase(damagedTiles.begin() + tile_id);
}