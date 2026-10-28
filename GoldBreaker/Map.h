#pragma once

#include "Player.h"
#include "Tiles.h"


int GetCell(int x, int y);

bool IsInMap(int x, int y);

void DisplayMap(int map[70], Player player);