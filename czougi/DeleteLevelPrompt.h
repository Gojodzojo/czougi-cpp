#pragma once
#include "Prompt.h"
#include "Level.h"
#include <SFML/Graphics.hpp>
#include "window.h"
#include "font.h"
#include "utils.h"
#include "Menu.h"

class DeleteLevelPrompt :
    public Prompt
{
	Level& level;
	sf::Text title;
	sf::Text okButtonText;
	sf::Text cancelButtonText;
	sf::RectangleShape background;

public:
	DeleteLevelPrompt(Level&);
	void draw(sf::RenderWindow&);
	std::pair<bool, Scene*> processEvent(sf::RenderWindow& window, sf::Event& event);
};

