#pragma once
#include <vector>
#include "Keybindings.h"
#include "Block.h"

const int PLAYER_SIZE = 2 * BLOCK_SIZE - 5; // -5 by komfortowo sie poruszac miedzy blokami
const sf::Vector2f PLAYER_SIZE_VEC(PLAYER_SIZE, PLAYER_SIZE);

const int EAGLE_SIZE = 2 * BLOCK_SIZE;
const sf::Vector2f EAGLE_SIZE_VEC(EAGLE_SIZE, EAGLE_SIZE);

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
	bool _isAlive;
	bool _hasCollision;
	
};

class Player
{
public:
	Player(PlayerColor, sf::Vector2f startPos = sf::Vector2f(0, 0));
	sf::Vector2f _startPos;
	Keybindings movemenet;
	sf::Sprite graphics;
	Eagle eagle;
	PlayerColor playerColor;

	void draw(sf::RenderWindow&);
	float _timeSinceDeath;
	bool _hasCollision;
	bool _isAlive;
};



