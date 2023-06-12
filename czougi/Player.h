#pragma once
#include <vector>
#include "Keybindings.h"
#include "Block.h"

enum PlayerColor
{
	Yellow = 0,
	Blue = 1,
	Green = 2,
	Red = 3
};

class Eagle
{
public:
	Eagle(PlayerColor);
	sf::Sprite graphics;

	void draw(sf::RenderWindow&);
};

class Player
{
public:
	Player(PlayerColor);
	sf::Sprite graphics;
	std::vector<Eagle> eagles;
	PlayerColor playerColor;

	void draw(sf::RenderWindow&);
};



