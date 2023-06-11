#pragma once
#include "Scene.h"
#include "font.h"
#include "Level.h"
#include "Window.h"
#include "Block.h"
#include "Bullet.h"
#include <vector>


#define MAX_NUMBER_OF_PLAYERS 4

class Arena :
	public Scene
{
private:
	sf::Text title;
	Level level;
	sf::RectangleShape ingameStats;
	sf::RectangleShape czoug1;
	sf::Clock clock;
	std::vector<Bullet> bullets[MAX_NUMBER_OF_PLAYERS];
	sf::Vector2f bulletDirection;
	//std::vector<sf::RectangleShape> allBlocks;
	int shootTimer[MAX_NUMBER_OF_PLAYERS] = { 0 };
	sf::Vector2f playerPositions[MAX_NUMBER_OF_PLAYERS];
	sf::Vector2f eaglePositions[MAX_NUMBER_OF_PLAYERS];
	sf::Vector2f bulletDirections[MAX_NUMBER_OF_PLAYERS];
	
	


public:
	Arena(Level);
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);
	//bool isColliding(sf::Vector2f aPos, sf::Vector2f aSize, sf::Vector2f bPos, sf::Vector2f bSize, float, bool);
	bool isCollidingWithBlocks(float velocity);

};