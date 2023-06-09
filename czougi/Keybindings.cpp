#include "Keybindings.h"

Keybindings::Keybindings(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key shot)
	: up(up), down(down), left(left), right(right), shot(shot)
{
}

Keybindings::Keybindings()
{
	Keybindings::up = sf::Keyboard::W;
	Keybindings::down = sf::Keyboard::S;
	Keybindings::left = sf::Keyboard::A;
	Keybindings::right = sf::Keyboard::D;
	Keybindings::shot = sf::Keyboard::E;
}