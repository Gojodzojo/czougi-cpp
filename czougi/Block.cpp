#include "Block.h"

using namespace sf;

const int BLOCK_SIZE = 30;

Block::Block(Texture* texture) : graphics(*texture)
{
	graphics.setScale(TEXTURE_SCALE);
}

void Block::draw(sf::RenderWindow& window)
{
	window.draw(graphics);
}

BrickWall::BrickWall() : Block(brickWallTexture)
{
}

ConcreteWall::ConcreteWall() : Block(concreteWallTexture)
{
}

Water::Water() : Block(waterTexture)
{
}

Leaves::Leaves() : Block(leavesTexture)
{
}