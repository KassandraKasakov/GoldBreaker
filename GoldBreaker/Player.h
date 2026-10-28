#pragma once


class Player
{
private:
	char name = 'H';

	int health = 3;
	int maxHealth = 3;
	int gold = 0;

	int x = 0;
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
	bool IsHere(int mapX, int mapY);
	void SetCoords(int x, int y);
	void MovePlayer();
	void MoveUp();
};
