#pragma once
#include <SFML/Graphics.hpp>

const float BACKGROUND_WIDTH = 700;
const float BACKGROUND_HEIGHT = 500;

class Prompt
{
public:
	virtual void draw(sf::RenderWindow&) = 0;

	// Je�li zwr�ci warto�� false, zamknij okno
	virtual bool processEvent(sf::RenderWindow& window, sf::Event& event) = 0;
};

