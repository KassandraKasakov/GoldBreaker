#include "Player.h"

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
#include "Tiles.h"


void Player::DisplayStats()
{

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Player stats :" << std::endl;
	SetConsoleTextAttribute(hConsole, 8);
	std::cout << "Coords : " << x << ' ' << y << std::endl;
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "Health : " << health << std::endl;
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << "Gold : " << gold << std::endl;
	std::cout << std::endl << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void Player::ShowName()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << name << ' ';
}

void Player::TakeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
	}
}

void Player::Heal(int pv)
{
	health += pv;

	if (health > maxHealth)
	{
		health = maxHealth;
	}
}

void Player::AddGold(int goldAmount)
{
	gold += goldAmount;	
}

bool Player::IsHere(int levelX, int levelY)
{
	return levelX == x && levelY == y;
}

void Player::SetCoords(int newX, int newY)
{
	x = newX;
	y = newY;
}


void Player::MovePlayer(Map& level)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(150));


	if (y == 9)
	{
		MoveUp(level);
	}
	else if (!IsBlockHere(x, y+1, level))
	{
		Fall();
	}
	else
	{
		MoveSide(level);
	}
	
}

void Player::MoveSide(Map level)
{
	char imput = _getch();
	int xDir = 0;
	int yDir = 0;

	switch (imput)
	{
	case 'd': // Right
		xDir = 1;
		break;
	case 'q': // Left
		xDir = -1;
		break;
	case 's': // Down
		yDir = 1;
		break;
	case 'z': // Up
		yDir = -1;
		break;
	}

	int newX = x + xDir;
	int newY = y + yDir;

	if (IsBlockHere(newX, newY, level))
	{
		Dig(level, newX, newY);
	}
	else
	{
		if (IsBlockWalkable(newX, newY, level))
		{
			if (IsInMap(newX, y) && !IsBlockHere(newX, newY, level))
			{
				SetCoords(newX, y);
			}
		}
	}
}


void Player::MoveUp(Map& level)
{
	SetCoords(x, 0);

	// Load next chunk
	level = CreateMap();
	ResetDamagedTiles();
}

void Player::Fall()
{
	SetCoords(x, y+1);
}


void Player::Dig(Map level, int x, int y)
{
	// Locate the tile
	int tileDamaged = GetDamagedTile(x, y);

	if (tileDamaged == -1)
	{
		AddDamagedTile(x, y, GetTileFromPos(x, y, level));
		tileDamaged = GetDamagedTile(x, y);
	}

	// Gain Gold (if the tile has any)
	Tile currentTile = GetTileFromPos(x, y, level);
	AddGold(currentTile.gold);

	// Damage the tile and remove it from the map if the tile is broken
	bool IsTileBroken;

	IsTileBroken = DamageTile(tileDamaged);
	if (IsTileBroken == true)
	{
		ChangeTileToAir(level, x, y);
	}
}