#include "Keybindings.h"

Keybindings playersKeybindings[4] = {
	Keybindings(sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::E),
	Keybindings(sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::RShift),
	Keybindings(sf::Keyboard::U, sf::Keyboard::J, sf::Keyboard::H, sf::Keyboard::K, sf::Keyboard::I),
	Keybindings(sf::Keyboard::Num8, sf::Keyboard::Num5, sf::Keyboard::Num4, sf::Keyboard::Num6, sf::Keyboard::Num9),
};

Keybindings::Keybindings(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key shot)
	: up(up), down(down), left(left), right(right), shot(shot)
{
}

void loadKeybindings()
{
}
