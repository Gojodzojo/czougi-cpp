#include "LevelsList.h"

using namespace sf;
using namespace std;

LevelsList::LevelsList()
{
	title.setFont(robotoRegular);
	title.setCharacterSize(50);
	title.setString("To jest LevelsList");
}

Scene* LevelsList::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	return nullptr;
}

Scene* LevelsList::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	return nullptr;
}

void LevelsList::draw(sf::RenderWindow& window)
{
	window.draw(title);
}