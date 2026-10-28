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
#include "Map.h"

class Player
{
private:
	char name = 'H';

	int health = 3;
	int maxHealth = 3;
	int gold = 0;

	int x = 3;
	int y = 0;
public:
	void DisplayStats();
	void ShowName();

	// Health Gestion
	void TakeDamage(int damage);
	void Heal(int pv);

	// Gold Gestion
	void AddGold(int goldAmount);

	// Map Gestion
	bool IsHere(int levelX, int levelY);
	void SetCoords(int x, int y);

	// Movements
	void MovePlayer(Map level);
	void MoveSide(Map level);
	void MoveUp(Map level);
	void Fall();

	// Dig
};
