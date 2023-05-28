#pragma once
#include <SFML/Graphics.hpp>

class Keybindings
{
public:
	sf::Keyboard::Key up;
	sf::Keyboard::Key down;
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;
	sf::Keyboard::Key shot;

	Keybindings(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key shot);
};

