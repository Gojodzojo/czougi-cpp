#include "DeleteLevelPrompt.h"

using namespace sf;
using namespace std;

DeleteLevelPrompt::DeleteLevelPrompt(Level& level) : level(level), background(Vector2f(BACKGROUND_WIDTH, BACKGROUND_HEIGHT))
{
	title.setFont(robotoRegular);
	title.setCharacterSize(50);

	// Skopiuj ustatienia do innych textów
	okButtonText = title;
	cancelButtonText = title;

	title.setString("Czy na pewno chcesz\nusunac poziom?");
	okButtonText.setString("Ok");
	cancelButtonText.setString("Anuluj");

	centerTextOrigin(title);
	centerTextOrigin(okButtonText);
	centerTextOrigin(cancelButtonText);

	title.setPosition(VIEW_CENTER_X, VIEW_CENTER_Y - 60);
	okButtonText.setPosition(VIEW_CENTER_X + BACKGROUND_WIDTH / 4, VIEW_CENTER_Y + 130);
	cancelButtonText.setPosition(VIEW_CENTER_X - BACKGROUND_WIDTH / 4, VIEW_CENTER_Y + 130);

	title.setFillColor(Color::Black);
	okButtonText.setFillColor(Color::Green);
	cancelButtonText.setFillColor(Color::Red);

	background.setOrigin(BACKGROUND_WIDTH / 2, BACKGROUND_HEIGHT / 2);
	background.setPosition(VIEW_CENTER_X, VIEW_CENTER_Y);
	background.setFillColor(Color::White);
	background.setOutlineColor(Color::Cyan);
	background.setOutlineThickness(5);
}

void DeleteLevelPrompt::draw(RenderWindow& window)
{
	window.draw(background);
	window.draw(title);
	window.draw(okButtonText);
	window.draw(cancelButtonText);
}

pair<bool, Scene*> DeleteLevelPrompt::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
	{
		Vector2f mousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));

		if (isHovered(cancelButtonText.getGlobalBounds(), mousePosition))
		{
			return make_pair(false, nullptr);
		}
		else if (isHovered(okButtonText.getGlobalBounds(), mousePosition))
		{
			level.deleteLevel();
			return make_pair(false, new Menu(4));
		}
	}

	return make_pair(true, nullptr);
}