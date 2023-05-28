#pragma once
#include "Scene.h"
#include "font.h"
#include "Level.h"

class Arena :
	public Scene
{
private:
	sf::Text title;
	Level level;
public:
	Arena(Level);
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);
};

