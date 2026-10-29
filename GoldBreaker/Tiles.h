#pragma once

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

enum Tile_Type
{
    Air = 0,
    Wall = 1,
    Dirt = 2
};

struct Tile {
    char name;
    int color;
    bool walkable = true;
    int durability = 1;
    int gold = 0;
};

// Tiles
const Tile air = { ' ', 1, true, 0, 0 };
const Tile wall = { '#', 12, false, 999, 0 };
const Tile dirt = { '%', 15, true, 1, 0 };

Tile const AllTiles[3] = { air, wall, dirt };

Tile GetTileFromPos(int x, int y, Map level);

bool IsBlockHere(int x, int y, Map level);

bool IsBlockWalkable(int x, int y, Map level);

void LoseDurability(int x, int y, Map& level);