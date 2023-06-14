#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "window.h"
#include "font.h"
#include "utils.h"
#include "Prompt.h"

class RenamePrompt : public Prompt 
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
	std::pair<bool, Scene*> processEvent(sf::RenderWindow& window, sf::Event& event);
};

