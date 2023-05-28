#include "Block.h"

using namespace sf;

Block::Block() : graphics(Vector2f(BLOCK_SIZE, BLOCK_SIZE))
{

}

void Block::draw(sf::RenderWindow& window)
{
	window.draw(graphics);
}

BrickWall::BrickWall()
{
	graphics.setFillColor(Color::Red);
}

ConcreteWall::ConcreteWall()
{
	graphics.setFillColor(Color::White);
}

Water::Water()
{
	graphics.setFillColor(Color::Blue);
}

Leaves::Leaves()
{
	graphics.setFillColor(Color::Green);
}