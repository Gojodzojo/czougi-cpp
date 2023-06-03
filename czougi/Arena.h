#pragma once
#include "Scene.h"
#include "font.h"
#include "Level.h"
#include "Window.h"
#include "Block.h"
#include <vector>
class Arena :
	public Scene
{
private:
	sf::Text title;
	Level level;
	sf::RectangleShape ingameStats;
	sf::RectangleShape czoug1;
	sf::Clock clock;
	std::vector<sf::CircleShape> Bullets;
public:
	Arena(Level);
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);
};

