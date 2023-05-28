#pragma once
#include <SFML/Graphics.hpp>

class Scene
{
public:
	// Funkcja kt�ra jest wywo�ywana gdy jest nowy event
	// Je�li ma zosta� zmieniona scena, zwraca wska�nik do niej, a je�li nie, zwraca nullptr
	virtual Scene* processEvent(sf::RenderWindow& window, sf::Event& event) = 0;

	// Funkcja w kt�rej znajduje si� g��wna cz�� logiki sceny
	// Je�li ma zosta� zmieniona scena, zwraca wska�nik do niej, a je�li nie, zwraca nullptr
	virtual Scene* doCalculations(sf::RenderWindow& window, float deltaTime) = 0;

	// Funkcja w kt�rej rysowane s� obiekty przez dan� scen�
	virtual void draw(sf::RenderWindow& window) = 0;
};

