#include "Arena.h"
using namespace sf;
using namespace std;

const int INGAMESTATS_WIDTH = VIEW_WIDTH - VIEW_HEIGHT - 100;

Arena::Arena(Level level): level(level), ingameStats(Vector2f(INGAMESTATS_WIDTH, VIEW_HEIGHT))

{
	title.setFont(robotoRegular),
	title.setCharacterSize(50),
	title.setString("To jest Arena");
	ingameStats.setOutlineColor(Color::White);
	ingameStats.setPosition(VIEW_WIDTH-INGAMESTATS_WIDTH, 0);
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
	window.draw(ingameStats);
}