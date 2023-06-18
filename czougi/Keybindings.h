#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>

class Keybindings
{
public:
	sf::Keyboard::Key up;
	sf::Keyboard::Key down;
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;
	sf::Keyboard::Key shot;
	Keybindings();
	Keybindings(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key shot);
};

extern Keybindings playersKeybindings[4];

// £adowanie ustawieñ z pliku
void loadKeybindings();
void saveKeybindings();