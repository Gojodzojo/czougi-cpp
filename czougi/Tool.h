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
	Tool(sf::Texture* texture, sf::Color selectionColor);
	bool isSelectable;	// true jeœli da siê zaznaczyæ obszar tym narzêdziem
	sf::Color selectionColor;	// Kolor zaznaczenia (jeœli isSelectable == true)
	virtual void drawOnToolbar(sf::RenderWindow& window) = 0;
	virtual bool isHovered(const sf::Vector2f&) = 0;
	virtual void setPosition(float, float) = 0;
	void drawAsCursor(sf::RenderWindow&, sf::Vector2f);
	// virtual void performAction() = 0;

protected:
	sf::Sprite graphics;
};

class BlockTool : public Tool
{
private:
	float x;
	float y;
	bool isSelectable = true;

public:
	BlockTool(sf::Texture* texture, sf::Color selectionColor);
	void drawOnToolbar(sf::RenderWindow& window);
	bool isHovered(const sf::Vector2f&);
	void setPosition(float, float);
};

class NonBlockTool : public Tool
{
public:
	NonBlockTool(sf::Texture* texture, sf::Color selectionColor);
	void drawOnToolbar(sf::RenderWindow& window);
	bool isHovered(const sf::Vector2f&);
	void setPosition(float, float);
};

class BrickWallTool : public BlockTool
{
public: 
	BrickWallTool() : BlockTool(brickWallTexture, sf::Color::Red) {};
};

class ConcreteWallTool : public BlockTool
{
public:
	ConcreteWallTool() : BlockTool(concreteWallTexture, sf::Color::White) {};
};

class WaterTool : public BlockTool
{
public:
	WaterTool() : BlockTool(waterTexture, sf::Color::Blue) {};
};

class LeavesTool : public BlockTool
{
public:
	LeavesTool() : BlockTool(leavesTexture, sf::Color::Green) {};
};

class TankTool : public NonBlockTool
{
private:
	bool isSelectable = false;

public:
	TankTool(sf::Texture*, PlayerColor);
	PlayerColor playerColor;
};

class EagleTool : public NonBlockTool
{
private:
	bool isSelectable = false;

public:
	EagleTool(sf::Texture*, PlayerColor);
	PlayerColor playerColor;
};

class EraserTool : public NonBlockTool
{
private:
	bool isSelectable = true;

public:
	EraserTool();
};