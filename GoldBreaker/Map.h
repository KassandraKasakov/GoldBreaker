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


#include "Tiles.h"
#include "Player.h"

struct Map {
    int width = 7;
    int height = 10;
    int* data = new int[width * height];
};

int GetCell(int x, int y);

bool IsInMap(int x, int y);

void DisplayMap(Map map, Player player);

Map CreateMap();