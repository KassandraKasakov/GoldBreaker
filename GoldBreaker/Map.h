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



struct Map {
    int width = 7;
    int height = 10;
    int* data = new int[width * height];
};

int GetCell(int x, int y);

bool IsInMap(int x, int y);

Map CreateMap();

void ChangeTileInMap(int x, int y, Map level);