#pragma once
#include <SFML/Graphics.hpp>

class Scene
{
public:
	// Funkcja która jest wywo³ywana gdy jest nowy event
	// Jeœli ma zostaæ zmieniona scena, zwraca wskaŸnik do niej, a jeœli nie, zwraca nullptr
	virtual Scene* processEvent(sf::RenderWindow& window, sf::Event& event) = 0;

	// Funkcja w której znajduje siê g³ówna czêœæ logiki sceny
	// Jeœli ma zostaæ zmieniona scena, zwraca wskaŸnik do niej, a jeœli nie, zwraca nullptr
	virtual Scene* doCalculations(sf::RenderWindow& window, float deltaTime) = 0;

	// Funkcja w której rysowane s¹ obiekty przez dan¹ scenê
	virtual void draw(sf::RenderWindow& window) = 0;
};

