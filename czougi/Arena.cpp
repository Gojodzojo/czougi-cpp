#include "Arena.h"

using namespace sf;
using namespace std;

Arena::Arena(Level level): level(level)
{
	title.setFont(robotoRegular);
	title.setCharacterSize(50);
	title.setString("To jest Arena");
}

Scene* Arena::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	return nullptr;
}

Scene* Arena::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	return nullptr;
}

void Arena::draw(sf::RenderWindow& window)
{
	window.draw(title);
}