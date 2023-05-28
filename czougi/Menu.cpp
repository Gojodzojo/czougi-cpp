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
	editorText = levelsListText;
	arenaText = levelsListText;

	float halfOfWidth = (float)VIEW_WIDTH / 2.0;

	levelsListText.setString("Poziomy");
	centerTextOrigin(levelsListText);
	levelsListText.setPosition(halfOfWidth, 100);

	settingsText.setString("Ustawienia");
	centerTextOrigin(settingsText);
	settingsText.setPosition(halfOfWidth, 200);

	creatorsText.setString("Twórcy");
	centerTextOrigin(creatorsText);
	creatorsText.setPosition(halfOfWidth, 300);

	editorText.setString("Edytor poziomów");
	centerTextOrigin(editorText);
	editorText.setPosition(halfOfWidth, 400);

	arenaText.setString("Arena");
	centerTextOrigin(arenaText);
	arenaText.setPosition(halfOfWidth, 500);
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

			if (isHovered(editorText.getGlobalBounds(), mousePosition))
				return new Editor(Level());

			if (isHovered(arenaText.getGlobalBounds(), mousePosition))
				return new Arena(Level());
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
	window.draw(editorText);
	window.draw(arenaText);
}