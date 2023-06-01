#pragma once
#include <SFML/Graphics.hpp>

const int BLOCK_SIZE = 30;

class Block
{
public:
	Block();
	sf::RectangleShape graphics;
	virtual void draw(sf::RenderWindow&);
};

class BrickWall : public Block
{
public:
	BrickWall();
};

class ConcreteWall : public Block
{
public:
	ConcreteWall();
};

class Water : public Block
{
public:
	Water();
};

class Leaves : public Block
{
public:
	Leaves();
};