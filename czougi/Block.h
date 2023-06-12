#pragma once
#include <SFML/Graphics.hpp>
#include "textures.h"

extern const int BLOCK_SIZE;

class Block
{
public:
	Block(sf::Texture*);
	sf::Sprite graphics;
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