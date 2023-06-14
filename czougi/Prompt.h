#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
#include "Scene.h"

const float BACKGROUND_WIDTH = 700;
const float BACKGROUND_HEIGHT = 500;

class Prompt
{
public:
	virtual void draw(sf::RenderWindow&) = 0;

	// Je�li zwr�ci pierwsz� warto�� nullptr, a drug� true, zostaw w��czone okno
	// Je�li zwr�ci pierwsz� warto�� nullptr, a drug� false, zamknij okno
	// Je�li zwr�ci pierwsz� warto�� jako wska�nik do sceny, zmie� scen�
	virtual std::pair<bool, Scene*> processEvent(sf::RenderWindow& window, sf::Event& event) = 0;
};

