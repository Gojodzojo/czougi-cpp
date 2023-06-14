#pragma once
#include "Scene.h"
#include "font.h"
#include <vector>
#include "Level.h"
#include "utils.h"
#include "window.h"
#include "Arena.h"
#include "Editor.h"
#include "Level.h"

class LevelsList :
    public Scene
{
private:
	std::vector<sf::Text> levelNames;
	sf::Text addLevelButton;
public:
	LevelsList();
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);
};

