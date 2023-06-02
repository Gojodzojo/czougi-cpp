#include "Arena.h"
#include "Block.h"
#include "Level.h"
#include "Menu.h"
using namespace sf;
using namespace std;

const int INGAMESTATS_WIDTH = VIEW_WIDTH - VIEW_HEIGHT - 100;

Arena::Arena(Level level) : level(level),
ingameStats(Vector2f(INGAMESTATS_WIDTH, VIEW_HEIGHT)),
czoug1(Vector2f(40, 40)),
cz1Position(0, 0)

{
	title.setFont(robotoRegular),
	title.setCharacterSize(50),
	title.setString("To jest Arena");
	ingameStats.setOutlineColor(Color::White);
	ingameStats.setPosition(VIEW_WIDTH-INGAMESTATS_WIDTH, 0);
	czoug1.setFillColor(Color::Green);
	Vector2f cz1Position(0, 0);
	czoug1.setPosition(cz1Position);

	float speed = 5.0f;
	Vector2f velocity(0, 0);

}

Scene* Arena::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	return nullptr;
}

Scene* Arena::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	float speed = 5.0f;
	Vector2f velocity(0, 0);
	//Keybindings p1(W,A,S,D,E);

	velocity.x = 0;
	velocity.y = 0;


	if (Keyboard::isKeyPressed(Keyboard::W))
		velocity.y = -speed;
	if (Keyboard::isKeyPressed(Keyboard::S))
		velocity.y = speed;
	if (Keyboard::isKeyPressed(Keyboard::A))
		velocity.x = -speed;
	if (Keyboard::isKeyPressed(Keyboard::D))
		velocity.x = speed;
	cz1Position += velocity;
	czoug1.setPosition(cz1Position);
	

	return nullptr;
}

void Arena::draw(sf::RenderWindow& window)
{
	//window.draw(title);
	window.draw(ingameStats);
	window.draw(czoug1);
}