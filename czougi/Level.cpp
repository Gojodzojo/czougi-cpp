#include "Level.h"

using namespace sf;

bool Level::isTileAvaliable(float x, float y)
{
	for (auto& block : brickWalls)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		if (blockPosition.x == x && blockPosition.y == y)
			return false;
	}

	for (auto& block : concreteWalls)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		if (blockPosition.x == x && blockPosition.y == y)
			return false;
	}

	for (auto& block : waters)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		if (blockPosition.x == x && blockPosition.y == y)
			return false;
	}

	for (auto& block : leaves)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		if (blockPosition.x == x && blockPosition.y == y)
			return false;
	}

	for (auto& player : players)
	{
		Vector2f playerPosition = player.graphics.getPosition();
		if (x == playerPosition.x && y == playerPosition.y ||
			x == playerPosition.x + BLOCK_SIZE && y == playerPosition.y ||
			x == playerPosition.x && y == playerPosition.y + BLOCK_SIZE ||
			x == playerPosition.x + BLOCK_SIZE && y == playerPosition.y + BLOCK_SIZE)
			return false;

		for (auto& eagle : player.eagles)
		{
			Vector2f eaglePosition = eagle.graphics.getPosition();
			if (x == eaglePosition.x && y == eaglePosition.y ||
				x == eaglePosition.x + BLOCK_SIZE && y == eaglePosition.y ||
				x == eaglePosition.x && y == eaglePosition.y + BLOCK_SIZE ||
				x == eaglePosition.x + BLOCK_SIZE && y == eaglePosition.y + BLOCK_SIZE)
				return false;
		}
	}

    return true;
}
