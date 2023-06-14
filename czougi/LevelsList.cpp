#include "LevelsList.h"

using namespace sf;
using namespace std;

LevelsList::LevelsList()
{
	vector<string> names = getLevelNames();

	levelNames.reserve(names.size());
	for (int i = 0; i < names.size(); i++)
	{
		Text level;

		level.setFont(robotoRegular);
		level.setCharacterSize(50);
		level.setString(names[i]);
		centerTextOrigin(level);
		level.setPosition(VIEW_CENTER_X, 100 + i * 100);

		levelNames.push_back(level);
	}

	addLevelButton.setFont(robotoRegular);
	addLevelButton.setCharacterSize(100);
	addLevelButton.setString("+");
	centerTextOrigin(addLevelButton);
	addLevelButton.setPosition(VIEW_WIDTH - 100, 50);
}

Scene* LevelsList::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	if (event.type == Event::MouseButtonReleased)
	{
		Vector2f mousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));

		for (Text& levelName : levelNames)
		{
			if (isHovered(levelName.getGlobalBounds(), mousePosition))
			{
				Level level(levelName.getString());
				
				if (event.mouseButton.button == Mouse::Left)
				{
					return new Arena(level);
				}
				else
				{
					return new Editor(level);
				}
			}
		}

		if (isHovered(addLevelButton.getGlobalBounds(), mousePosition))
		{
			return new Editor(Level());
		}
	}

	return nullptr;
}

Scene* LevelsList::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	return nullptr;
}

void LevelsList::draw(sf::RenderWindow& window)
{
	for (Text& levelName : levelNames)
	{
		window.draw(levelName);
	}

	window.draw(addLevelButton);
}