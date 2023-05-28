#pragma once
#include "Scene.h"
#include "font.h"

class LevelsList :
    public Scene
{
private:
	sf::Text title;
public:
	LevelsList();
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);
};

