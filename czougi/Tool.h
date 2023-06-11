#pragma once
#include "font.h"
#include "Level.h"
#include "Block.h"
#include "window.h"
#include "utils.h"
#include "textures.h"

class Tool
{
public:
	Tool(sf::Texture* texture, sf::Color selectionColor, bool isSelectable);
	bool isSelectable;	// true jeœli da siê zaznaczyæ obszar tym narzêdziem
	sf::Color selectionColor;	// Kolor zaznaczenia (jeœli isSelectable == true)
	virtual void drawOnToolbar(sf::RenderWindow& window) = 0;
	virtual bool isHovered(const sf::Vector2f&) = 0;
	virtual void setPosition(float, float) = 0;
	void drawAsCursor(sf::RenderWindow&, sf::Vector2f);
	virtual void performAction(sf::Vector2f&, sf::Vector2f&, Level&) = 0;

protected:
	sf::Sprite graphics;
};

class BlockTool : public Tool
{
private:
	float x;
	float y;
public:
	BlockTool(sf::Texture* texture, sf::Color selectionColor);
	void drawOnToolbar(sf::RenderWindow& window);
	bool isHovered(const sf::Vector2f&);
	void setPosition(float, float);
};

class NonBlockTool : public Tool
{
public:
	NonBlockTool(sf::Texture* texture, sf::Color selectionColor, bool isSelectable);
	void drawOnToolbar(sf::RenderWindow& window);
	bool isHovered(const sf::Vector2f&);
	void setPosition(float, float);
};

class BrickWallTool : public BlockTool
{
public: 
	BrickWallTool() : BlockTool(brickWallTexture, sf::Color::Red) {};
	void performAction(sf::Vector2f&, sf::Vector2f&, Level&);
};

class ConcreteWallTool : public BlockTool
{
public:
	ConcreteWallTool() : BlockTool(concreteWallTexture, sf::Color::White) {};
	void performAction(sf::Vector2f&, sf::Vector2f&, Level&);
};

class WaterTool : public BlockTool
{
public:
	WaterTool() : BlockTool(waterTexture, sf::Color::Blue) {};
	void performAction(sf::Vector2f&, sf::Vector2f&, Level&);
};

class LeavesTool : public BlockTool
{
public:
	LeavesTool() : BlockTool(leavesTexture, sf::Color::Green) {};
	void performAction(sf::Vector2f&, sf::Vector2f&, Level&);
};

class TankTool : public NonBlockTool
{
public:
	TankTool(sf::Texture*, PlayerColor);
	void performAction(sf::Vector2f&, sf::Vector2f&, Level&);
	PlayerColor playerColor;
};

class EagleTool : public NonBlockTool
{
public:
	EagleTool(sf::Texture*, PlayerColor);
	void performAction(sf::Vector2f&, sf::Vector2f&, Level&);
	PlayerColor playerColor;
};

class EraserTool : public NonBlockTool
{
public:
	EraserTool();
	void performAction(sf::Vector2f&, sf::Vector2f&, Level&);
};