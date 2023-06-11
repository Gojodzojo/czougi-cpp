#include "Tool.h"

using namespace sf;

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

EagleTool::EagleTool(Texture* texture, PlayerColor playerColor) : playerColor(playerColor), NonBlockTool(texture, Color::Black, false)
{
}

EraserTool::EraserTool() :  NonBlockTool(eraserTexture, Color::Red, true)
{
}