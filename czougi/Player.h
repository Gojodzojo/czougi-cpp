#pragma once
#include <vector>
#include "Keybindings.h"
#include "Block.h"

class Eagle
{
public:
	Eagle(int playerNumber);
	sf::RectangleShape graphics;

	void draw(sf::RenderWindow&);
};

class Player
{
public:
	Player(int playerNumber);
	sf::RectangleShape graphics;
	std::vector<Eagle> eagles;

	void draw(sf::RenderWindow&);
};



