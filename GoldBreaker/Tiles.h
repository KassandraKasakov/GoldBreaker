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
#include <vector>

#include "Map.h"

enum Tile_Type
{
    Air = 0,
    Wall = 1,
    Dirt = 2,
    Stone = 3,
    GoldOre_Low = 4,
    GoldOre_Medium = 5,
    GoldOre_High = 6,
};

struct Tile {
    char name_Display;
    char name_Parser;
    int color;
    bool walkable = true;
    int durability = 1;
    int gold = 0;
    int x;
    int y;
};

// Tiles
const Tile air = { ' ', ' ', 1, true, 0, 0 };
const Tile wall = { '#', '#', 12, false, 999, 0 };
const Tile dirt = { '#', '%', 7, true, 1, 0 };
const Tile stone = { '#', 'S', 8, true, 2, 0 };

const Tile goldOre_Low = { '*', '*' , 6, true, 1, 3 };
const Tile goldOre_Medium = { '+', '+' , 6, true, 2, 7 };
const Tile goldOre_High = { 'X', 'X' , 6, true, 3, 15 };

Tile const AllTiles[7] = { air, wall, dirt, stone, goldOre_Low, goldOre_Medium, goldOre_High };

const int TileNumber = 7;


Tile GetTileFromPos(int x, int y, Map level);

bool IsBlockHere(int x, int y, Map level);

bool IsBlockWalkable(int x, int y, Map level);

// Damaged Tiles


int GetDamagedTile(int x, int y);

void AddDamagedTile(int x, int y, Tile tile);

bool DamageTile(int tile_id);

void RemoveDamagedTile(int tile_id);

void ResetDamagedTiles();