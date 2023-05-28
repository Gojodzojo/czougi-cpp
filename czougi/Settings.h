#pragma once
#include "Scene.h"
#include "font.h"
#include "Keybindings.h"

extern Keybindings playersKeybindings[4];

void loadSettings();

class Settings :
	public Scene
{
private:
	sf::Text title;
public:
	Settings();
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);
};

