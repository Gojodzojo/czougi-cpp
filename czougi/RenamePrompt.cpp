#include "RenamePrompt.h"

using namespace sf;
using namespace std;


RenamePrompt::RenamePrompt(Level& level) : level(level), background(Vector2f(BACKGROUND_WIDTH, BACKGROUND_HEIGHT))
{
	title.setFont(robotoRegular);
	title.setCharacterSize(50);

	// Skopiuj ustatienia do innych textów
	newName = title;
	errorText = title;
	okButtonText = title;
	cancelButtonText = title;

	title.setString("Nowa nazwa poziomu:");
	newName.setString(level.name);
	okButtonText.setString("Ok");
	cancelButtonText.setString("Anuluj");

	centerTextOrigin(title);
	centerTextOrigin(newName);
	centerTextOrigin(okButtonText);
	centerTextOrigin(cancelButtonText);

	title.setPosition(SCREEN_CENTER_X, SCREEN_CENTER_Y - 130);
	newName.setPosition(SCREEN_CENTER_X, SCREEN_CENTER_Y - 60);
	errorText.setPosition(SCREEN_CENTER_X, SCREEN_CENTER_Y + 30);
	okButtonText.setPosition(SCREEN_CENTER_X + BACKGROUND_WIDTH / 4, SCREEN_CENTER_Y + 130);
	cancelButtonText.setPosition(SCREEN_CENTER_X - BACKGROUND_WIDTH / 4, SCREEN_CENTER_Y + 130);

	title.setFillColor(Color::Black);
	newName.setFillColor(Color::Blue);
	errorText.setFillColor(Color::Red);
	okButtonText.setFillColor(Color::Green);
	cancelButtonText.setFillColor(Color::Red);

	background.setOrigin(BACKGROUND_WIDTH / 2, BACKGROUND_HEIGHT / 2);
	background.setPosition(SCREEN_CENTER_X, SCREEN_CENTER_Y);
	background.setFillColor(Color::White);
	background.setOutlineColor(Color::Cyan);
	background.setOutlineThickness(5);
}

void RenamePrompt::draw(RenderWindow& window)
{
	window.draw(background);
	window.draw(title);
	window.draw(newName);
	window.draw(errorText);
	window.draw(okButtonText);
	window.draw(cancelButtonText);
}

bool RenamePrompt::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	string newNameString = newName.getString();

	if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
	{
		Vector2f mousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));

		if (isHovered(cancelButtonText.getGlobalBounds(), mousePosition))
		{
			newName.setString(level.name);
			errorText.setString("");
			return false;
		}
		else if (isHovered(okButtonText.getGlobalBounds(), mousePosition) && newNameString.length() > 0 && (isLevelNameAvaliable(newNameString) || newNameString == level.name))
		{
			level.rename(newNameString);
			errorText.setString("");
			return false;
		}
	}
	else if (event.type == Event::KeyPressed)
	{
		if (event.key.code == Keyboard::Backspace)
		{
			newName.setString(newNameString.substr(0, newNameString.length() - 1));
		}
		else if (newNameString.length() <= 20)
		{
			if (event.key.code >= Keyboard::A && event.key.code <= Keyboard::Z)
			{
				char character = event.key.code + 65;
				if (!event.key.shift)
				{
					character += 32;
				}

				newName.setString(newNameString + character);
			}
			else if (event.key.code >= Keyboard::Num0 && event.key.code <= Keyboard::Num9)
			{
				char character = event.key.code + 22;
				newName.setString(newNameString + character);
			}
			else if (event.key.code == Keyboard::Space && newNameString.length() > 0)
			{
				newName.setString(newNameString + ' ');
			}
		}

		newNameString = newName.getString();

		if (newNameString.length() == 0)
		{
			errorText.setString("Nazwa jest pusta");
		}
		else if (!isLevelNameAvaliable(newNameString) && newNameString != level.name)
		{
			errorText.setString("Nazwa jest zajêta");
		}
		else
		{
			errorText.setString("");
		}

		centerTextOrigin(errorText);
	}

	centerTextOrigin(newName);

	return true;
}
