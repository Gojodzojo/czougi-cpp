#include "Menu.h"

using namespace sf;
using namespace std;

Menu::Menu()
{
	levelsListText.setFont(robotoRegular);
	levelsListText.setCharacterSize(50);

	// Skopiuj ustatienia levelsText do innych textów
	settingsText = levelsListText;
	creatorsText = levelsListText;

	levelsListText.setString("Poziomy");
	centerTextOrigin(levelsListText);
	levelsListText.setPosition(VIEW_CENTER_X, 100);

	settingsText.setString("Ustawienia");
	centerTextOrigin(settingsText);
	settingsText.setPosition(VIEW_CENTER_X, 200);

	creatorsText.setString("Twórcy");
	centerTextOrigin(creatorsText);
	creatorsText.setPosition(VIEW_CENTER_X, 300);
}

Scene* Menu::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
	{
			Vector2f mousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
			
			if (isHovered(levelsListText.getGlobalBounds(), mousePosition))
				return new LevelsList();

			if (isHovered(settingsText.getGlobalBounds(), mousePosition))
				return new Settings();

			if (isHovered(creatorsText.getGlobalBounds(), mousePosition))
				return new Creators();
	}

	return nullptr;
}

Scene* Menu::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	return nullptr;
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(levelsListText);
	window.draw(settingsText);
	window.draw(creatorsText);
}