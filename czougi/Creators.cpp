#include "Creators.h"

using namespace sf;
using namespace std;

Creators::Creators()
{
	title.setFont(robotoRegular);
	title.setCharacterSize(50);
	title.setString("To jest Creators");
}

Scene* Creators::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	return nullptr;
}

Scene* Creators::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	return nullptr;
}

void Creators::draw(sf::RenderWindow& window)
{
	window.draw(title);
}