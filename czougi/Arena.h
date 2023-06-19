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
	sf::Text numberOfDeathsP1;
	sf::Text numberOfDeathsP2;
	sf::Text numberOfDeathsP3;
	sf::Text numberOfDeathsP4;
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
	sf::Sprite iconPlayer1;
	sf::Sprite iconPlayer2;
	sf::Sprite iconPlayer3;
	sf::Sprite iconPlayer4;
	sf::Texture* playersColors[4] = { yellowTankTexture,blueTankTexture,greenTankTexture, redTankTexture };
	sf::Color playersTextColors[4] = { sf::Color::Yellow, sf::Color::Blue, sf::Color::Green, sf::Color::Red };
	sf::Sprite goBackIcon;


	


public:
	Arena(Level);
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);

};