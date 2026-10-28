#include "Tiles.h"
#include "Map.h"
#include "Player.h"

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>



void Player::DisplayStats()
{

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Player stats :" << std::endl;
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "Health : " << health << std::endl;
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << "Gold : " << gold << std::endl;
	std::cout << std::endl << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void Player::ShowName()
{
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

bool Player::IsHere(int mapX, int mapY)
{
	return mapX == x && mapY == y;
}

void Player::SetCoords(int newX, int newY)
{
	x = newX;
	y = newY;
}


void Player::MovePlayer()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(150));

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
	}

	int newX = x + xDir;
	int newY = y + yDir;

	if (IsInMap(newX, newY))
	{
		SetCoords(newX, newY);
		MoveUp();
	}
}

void Player::MoveUp()
{
	if (y == 7)
	{
		SetCoords(x, 1);
	}
}