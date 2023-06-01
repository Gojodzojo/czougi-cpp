#pragma once
#include "Scene.h"
#include "font.h"
#include "Level.h"
#include "Block.h"
#include "window.h"
#include "utils.h"
#include "textures.h"

class Editor :
	public Scene
{
private:
	Level level;
	sf::Text levelName;
	sf::RectangleShape toolbarBackground;
	sf::Sprite brickWallSprite;
	sf::Sprite concreteWallSprite;
	sf::Sprite waterSprite;
	sf::Sprite leavesSprite;
	sf::Sprite yellowTankSprite;
	sf::Sprite blueTankSprite;
	sf::Sprite greenTankSprite;
	sf::Sprite redTankSprite;
	sf::Sprite yellowEagleSprite;
	sf::Sprite blueEagleSprite;
	sf::Sprite greenEagleSprite;
	sf::Sprite redEagleSprite;
	sf::Sprite eraserIcon;
	sf::RectangleShape horizontalLine;
	sf::RectangleShape verticalLine;
	sf::RectangleShape playIcon;
	sf::RectangleShape saveIcon;
	sf::RectangleShape deleteIcon;

public:
	Editor(Level);
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);
};

