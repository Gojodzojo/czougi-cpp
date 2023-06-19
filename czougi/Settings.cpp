#include "Settings.h"

using namespace sf;
using namespace std;

Keybindings playersKeybindings[4] = {
	Keybindings(Keyboard::W, Keyboard::S, Keyboard::A, Keyboard::D, Keyboard::E),
	Keybindings(Keyboard::Up, Keyboard::Down, Keyboard::Left, Keyboard::Right, Keyboard::Space),
	Keybindings(Keyboard::Z, Keyboard::X, Keyboard::C, Keyboard::V, Keyboard::B),
	Keybindings(Keyboard::H, Keyboard::U, Keyboard::J, Keyboard::K, Keyboard::L),
};

// £adowanie ustawieñ z pliku
void loadSettings()
{
	
}

Settings::Settings()
{
	title.setFont(robotoRegular);
	title.setCharacterSize(50);
	title.setString("To jest Settings");
}

Scene* Settings::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	return nullptr;
}

Scene* Settings::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	return nullptr;
}

void Settings::draw(sf::RenderWindow& window)
{
	window.draw(title);
}