#pragma once
#include <iostream>
#include "Scene.h"
#include "font.h"
#include "window.h"
#include "utils.h"
#include "LevelsList.h"
#include "Settings.h"
#include "Creators.h"
#include "Editor.h"
#include "Arena.h"

class Menu :
    public Scene
{
private:
	sf::Text levelsListText;
	sf::Text settingsText;
	sf::Text creatorsText;
	sf::Text editorText;
	sf::Text arenaText;
public:
	Menu();
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);
};

