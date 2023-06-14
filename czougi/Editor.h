#pragma once
#include "Scene.h"
#include "font.h"
#include "Level.h"
#include "Block.h"
#include "window.h"
#include "utils.h"
#include "textures.h"
#include "Tool.h"
#include <vector>
#include <memory>
#include <iostream>
#include "LevelsList.h"
#include "Prompt.h"
#include "RenamePrompt.h"
#include "InvalidLevelPrompt.h"

class Editor :
	public Scene
{
private:
	Level level;
	sf::Text levelName;
	sf::Vector2f mousePosition;
	std::unique_ptr<Tool> tools[13];
	int activeToolIndex;
	bool isSelecting;
	sf::RectangleShape selectionRectangle;
	sf::RectangleShape toolbarBackground;
	sf::RectangleShape horizontalLine;
	sf::RectangleShape verticalLine;
	sf::RectangleShape playIcon;
	sf::RectangleShape saveIcon;
	sf::RectangleShape deleteIcon;
	std::unique_ptr<Prompt> prompt;

public:
	Editor(Level);
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);
};

