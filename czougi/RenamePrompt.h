#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "window.h"
#include "font.h"
#include "utils.h"

class RenamePrompt
{
	Level& level;
	sf::Text newName;
	sf::Text title;
	sf::Text errorText;
	sf::Text okButtonText;
	sf::Text cancelButtonText;
	sf::RectangleShape background;
	
public:
	RenamePrompt(Level&);
	void draw(sf::RenderWindow&);
	void processEvent(sf::RenderWindow& window, sf::Event& event);
	bool isOpened;
};

