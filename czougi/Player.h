#pragma once
#include <vector>
#include "Keybindings.h"
#include "Block.h"

class Eagle
{
public:
	int _playerNumber;
	Eagle(int playerNumber);
	sf::RectangleShape graphics;
	void draw(sf::RenderWindow&);
};

class Player
{
public:
	int _playerNumber;
	Player(int playerNumber, sf::Vector2f startPos);
	sf::RectangleShape graphics;
	sf::Vector2f _startPos;
	Keybindings movemenet;
	void draw(sf::RenderWindow&);
};



