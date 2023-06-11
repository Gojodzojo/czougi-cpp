#include "Tool.h"

using namespace sf;
using namespace std;

Tool::Tool(sf::Texture* texture, sf::Color selectionColor, bool isSelectable) :
	graphics(*texture),
	selectionColor(selectionColor),
	isSelectable(isSelectable)
{
	graphics.setScale(TEXTURE_SCALE);
}

void Tool::drawAsCursor(RenderWindow& window, Vector2f mousePosition)
{
	Vector2f graphicsPosition = graphics.getPosition();
	graphics.setPosition(mousePosition);
	window.draw(graphics);
	graphics.setPosition(graphicsPosition);
}

BlockTool::BlockTool(sf::Texture* texture, sf::Color selectionColor) : Tool(texture, selectionColor, true)
{
}

void BlockTool::drawOnToolbar(RenderWindow& window)
{
	graphics.setPosition(Vector2f(x, y));
	window.draw(graphics);
	graphics.setPosition(Vector2f(x + BLOCK_SIZE, y));
	window.draw(graphics);
	graphics.setPosition(Vector2f(x, y + BLOCK_SIZE));
	window.draw(graphics);
	graphics.setPosition(Vector2f(x + BLOCK_SIZE, y + BLOCK_SIZE));
	window.draw(graphics);
}

NonBlockTool::NonBlockTool(sf::Texture* texture, sf::Color selectionColor, bool isSelectable) : Tool(texture, selectionColor, isSelectable)
{
}

void NonBlockTool::drawOnToolbar(sf::RenderWindow& window)
{
	Vector2f toolPosition = graphics.getPosition();
	graphics.setPosition(Vector2f(toolPosition.x, toolPosition.y));
	window.draw(graphics);
}

bool BlockTool::isHovered(const Vector2f& mousePosition)
{
	return ::isHovered(FloatRect(x, y, BLOCK_SIZE * 2, BLOCK_SIZE * 2), mousePosition);
}

void BlockTool::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

bool NonBlockTool::isHovered(const Vector2f& mousePosition)
{
	Vector2f toolPosition = graphics.getPosition();
	return ::isHovered(FloatRect(toolPosition.x, toolPosition.y, BLOCK_SIZE * 2, BLOCK_SIZE * 2), mousePosition);
}

void NonBlockTool::setPosition(float x, float y)
{
	graphics.setPosition(x, y);
}

TankTool::TankTool(Texture* texture, PlayerColor playerColor) : playerColor(playerColor), NonBlockTool(texture, Color::Black, false)
{
}

void TankTool::performAction(Vector2f& cursorPosition, Vector2f& selectionRectanglePosition, Level& level)
{
	if (level.isTileAvaliable(cursorPosition.x, cursorPosition.y) &&
		level.isTileAvaliable(cursorPosition.x + BLOCK_SIZE, cursorPosition.y) &&
		level.isTileAvaliable(cursorPosition.x, cursorPosition.y + BLOCK_SIZE) &&
		level.isTileAvaliable(cursorPosition.x + BLOCK_SIZE, cursorPosition.y + BLOCK_SIZE))
	{
		// Check if player already exists, and if it does, change its position
		for (Player& player : level.players)
		{
			if (player.playerColor == this->playerColor)
			{
				player.graphics.setPosition(cursorPosition.x, cursorPosition.y);
				return;
			}
		}

		// Add a new player
		Player player(playerColor);
		player.graphics.setPosition(cursorPosition.x, cursorPosition.y);
		level.players.push_back(player);
	}
}

EagleTool::EagleTool(Texture* texture, PlayerColor playerColor) : playerColor(playerColor), NonBlockTool(texture, Color::Black, false)
{
}

void EagleTool::performAction(Vector2f& cursorPosition, Vector2f& selectionRectanglePosition, Level& level)
{
	if (level.isTileAvaliable(cursorPosition.x, cursorPosition.y) &&
		level.isTileAvaliable(cursorPosition.x + BLOCK_SIZE, cursorPosition.y) &&
		level.isTileAvaliable(cursorPosition.x, cursorPosition.y + BLOCK_SIZE) &&
		level.isTileAvaliable(cursorPosition.x + BLOCK_SIZE, cursorPosition.y + BLOCK_SIZE))
	{
		for (Player& player : level.players)
		{
			if (player.playerColor == this->playerColor)
			{
				Eagle eagle(playerColor);
				eagle.graphics.setPosition(cursorPosition.x, cursorPosition.y);
				player.eagles.push_back(eagle);
				return;
			}
		}
	}
}

void BrickWallTool::performAction(Vector2f& cursorPosition, Vector2f& selectionRectanglePosition, Level& level)
{
	float startX = min(cursorPosition.x, selectionRectanglePosition.x);
	float endX = max(cursorPosition.x, selectionRectanglePosition.x);
	float startY = min(cursorPosition.y, selectionRectanglePosition.y);
	float endY = max(cursorPosition.y, selectionRectanglePosition.y);

	for (float x = startX; x <= endX; x += BLOCK_SIZE)
	{
		for (float y = startY; y <= endY; y += BLOCK_SIZE)
		{
			if(level.isTileAvaliable(x, y))
			{
				BrickWall block;
				block.graphics.setPosition(x, y);
				level.brickWalls.push_back(block);
			}
		}
	}
}

void ConcreteWallTool::performAction(Vector2f& cursorPosition, Vector2f& selectionRectanglePosition, Level& level)
{
	float startX = min(cursorPosition.x, selectionRectanglePosition.x);
	float endX = max(cursorPosition.x, selectionRectanglePosition.x);
	float startY = min(cursorPosition.y, selectionRectanglePosition.y);
	float endY = max(cursorPosition.y, selectionRectanglePosition.y);

	for (float x = startX; x <= endX; x += BLOCK_SIZE)
	{
		for (float y = startY; y <= endY; y += BLOCK_SIZE)
		{
			if (level.isTileAvaliable(x, y))
			{
				ConcreteWall block;
				block.graphics.setPosition(x, y);
				level.concreteWalls.push_back(block);
			}
		}
	}
}

void WaterTool::performAction(Vector2f& cursorPosition, Vector2f& selectionRectanglePosition, Level& level)
{
	float startX = min(cursorPosition.x, selectionRectanglePosition.x);
	float endX = max(cursorPosition.x, selectionRectanglePosition.x);
	float startY = min(cursorPosition.y, selectionRectanglePosition.y);
	float endY = max(cursorPosition.y, selectionRectanglePosition.y);

	for (float x = startX; x <= endX; x += BLOCK_SIZE)
	{
		for (float y = startY; y <= endY; y += BLOCK_SIZE)
		{
			if (level.isTileAvaliable(x, y))
			{
				Water block;
				block.graphics.setPosition(x, y);
				level.waters.push_back(block);
			}
		}
	}
}

void LeavesTool::performAction(Vector2f& cursorPosition, Vector2f& selectionRectanglePosition, Level& level)
{
	float startX = min(cursorPosition.x, selectionRectanglePosition.x);
	float endX = max(cursorPosition.x, selectionRectanglePosition.x);
	float startY = min(cursorPosition.y, selectionRectanglePosition.y);
	float endY = max(cursorPosition.y, selectionRectanglePosition.y);

	for (float x = startX; x <= endX; x += BLOCK_SIZE)
	{
		for (float y = startY; y <= endY; y += BLOCK_SIZE)
		{
			if (level.isTileAvaliable(x, y))
			{
				Leaves block;
				block.graphics.setPosition(x, y);
				level.leaves.push_back(block);
			}
		}
	}
}

EraserTool::EraserTool() : NonBlockTool(eraserTexture, Color::Red, true)
{
}

void EraserTool::performAction(Vector2f& cursorPosition, Vector2f& selectionRectanglePosition, Level& level)
{
	float startX = min(cursorPosition.x, selectionRectanglePosition.x);
	float endX = max(cursorPosition.x, selectionRectanglePosition.x);
	float startY = min(cursorPosition.y, selectionRectanglePosition.y);
	float endY = max(cursorPosition.y, selectionRectanglePosition.y);

	for (float x = startX; x <= endX; x += BLOCK_SIZE)
	{
		for (float y = startY; y <= endY; y += BLOCK_SIZE)
		{
			for (int i = 0; i < level.brickWalls.size(); i++)
			{
				Vector2f blockPosition = level.brickWalls[i].graphics.getPosition();
				if (x == blockPosition.x && y == blockPosition.y)
				{
					level.brickWalls.erase(level.brickWalls.begin() + i);
					goto cnt;
				}
			}

			for (int i = 0; i < level.concreteWalls.size(); i++)
			{
				Vector2f blockPosition = level.concreteWalls[i].graphics.getPosition();
				if (x == blockPosition.x && y == blockPosition.y)
				{
					level.concreteWalls.erase(level.concreteWalls.begin() + i);
					goto cnt;
				}
			}

			for (int i = 0; i < level.waters.size(); i++)
			{
				Vector2f blockPosition = level.waters[i].graphics.getPosition();
				if (x == blockPosition.x && y == blockPosition.y)
				{
					level.waters.erase(level.waters.begin() + i);
					goto cnt;
				}
			}

			for (int i = 0; i < level.leaves.size(); i++)
			{
				Vector2f blockPosition = level.leaves[i].graphics.getPosition();
				if (x == blockPosition.x && y == blockPosition.y)
				{
					level.leaves.erase(level.leaves.begin() + i);
					goto cnt;
				}
			}

			for (int i = 0; i < level.players.size(); i++)
			{
				Vector2f playerPosition = level.players[i].graphics.getPosition();
				if (x == playerPosition.x && y == playerPosition.y ||
					x == playerPosition.x + BLOCK_SIZE && y == playerPosition.y ||
					x == playerPosition.x && y == playerPosition.y + BLOCK_SIZE ||
					x == playerPosition.x + BLOCK_SIZE && y == playerPosition.y + BLOCK_SIZE)
				{
					level.players.erase(level.players.begin() + i);
					goto cnt;
				}
				
				for (int j = 0; j < level.players[i].eagles.size(); j++)
				{
					Vector2f eaglePosition = level.players[i].eagles[j].graphics.getPosition();
					if (x == eaglePosition.x && y == eaglePosition.y ||
						x == eaglePosition.x + BLOCK_SIZE && y == eaglePosition.y ||
						x == eaglePosition.x && y == eaglePosition.y + BLOCK_SIZE ||
						x == eaglePosition.x + BLOCK_SIZE && y == eaglePosition.y + BLOCK_SIZE)
					{
						level.players[i].eagles.erase(level.players[i].eagles.begin() + j);
						goto cnt;
					}
				}
			}

			cnt:;
		}
	}
}