#pragma once
#include "Scene.h"
#include "font.h"
#include "Level.h"
#include "Window.h"
#include "Block.h"
#include "Bullet.h"
#include <vector>
#include "Tool.h"


#define MAX_NUMBER_OF_PLAYERS 4

class Arena :
	public Scene
{
private:
	sf::Text title;
	sf::Text winnerText;
	sf::Text backToMenu;
	Level level;
	sf::RectangleShape ingameStats;
	sf::Clock clock;
	std::vector<Bullet> bullets[MAX_NUMBER_OF_PLAYERS];
	sf::Vector2f bulletDirection;
	int shootTimer[MAX_NUMBER_OF_PLAYERS] = { 0 };
	sf::Vector2f playerPositions[MAX_NUMBER_OF_PLAYERS];
	sf::Vector2f eaglePositions[MAX_NUMBER_OF_PLAYERS];
	sf::Vector2f bulletDirections[MAX_NUMBER_OF_PLAYERS];
	sf::Time elapsed = clock.getElapsedTime();
	bool gameEnded;
	bool gameOver;
	
	


public:
	Arena(Level);
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);

};