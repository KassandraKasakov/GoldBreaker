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
#include "Player.h"


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


void Player::MovePlayer(Map level)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(150));


	if (y == 7)
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

	switch (imput)
	{
	case 'd': // Right
		xDir = 1;
		break;
	case 'q': // Left
		xDir = -1;
		break;
	}

	int newX = x + xDir;

	if (IsInMap(newX, y) && !IsBlockHere(newX, y, level))
	{
		SetCoords(newX, y);
	}
}


void Player::MoveUp(Map level)
{
	SetCoords(x, 1);
	level = CreateMap();
}

void Player::Fall()
{
	SetCoords(x, y+1);
}