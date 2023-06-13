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
	bool isPresent;

	void draw(sf::RenderWindow&);
};

class Player
{
public:
	Player(PlayerColor);
	sf::Sprite graphics;
	Eagle eagle;
	PlayerColor playerColor;

	void draw(sf::RenderWindow&);
};



