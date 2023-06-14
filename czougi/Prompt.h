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

	// Jeœli zwróci pierwsz¹ wartoœæ nullptr, a drug¹ true, zostaw w³¹czone okno
	// Jeœli zwróci pierwsz¹ wartoœæ nullptr, a drug¹ false, zamknij okno
	// Jeœli zwróci pierwsz¹ wartoœæ jako wskaŸnik do sceny, zmieñ scenê
	virtual std::pair<bool, Scene*> processEvent(sf::RenderWindow& window, sf::Event& event) = 0;
};

