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





int GetCell(int x, int y)
{
	return y * 7 + x;
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

Map CreateMap()
{
	Map level;

	// Create a random chunk path
	int random = rand() % 5 + 1; // random number between 1 and 3

	std::string path = "chunks/";
	path.append(std::to_string(random));
	path.append(".txt");

	// Opening File
	std::ifstream chunk(path);

	// If error opening file
	if (!chunk.is_open()) {
		std::cerr << "No Chunk!";
		return level;
	}

	level.data = new int[level.height * level.width];

	std::string line;
	int n = -1;
	int currentLine = 0;

	// Setting the map tiles
	while (std::getline(chunk, line)) {

		for (int i = 0;i < 7;i++) {

			n++;

			for (int t = 0; t < 3; t++) {
				if (line[i] == AllTiles[t].name) {
					level.data[n] = t;
				}
			}
		}
		currentLine++;
	}

	// Closing File
	chunk.close();

	return level;
}