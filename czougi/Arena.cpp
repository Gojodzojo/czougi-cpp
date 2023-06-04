#include "Arena.h"
#include "Block.h"
#include "Level.h"
#include "Menu.h"
#include<vector>
using namespace sf;
using namespace std;

const int INGAMESTATS_WIDTH = VIEW_WIDTH - VIEW_HEIGHT - 100;

Arena::Arena(Level level) : level(level),
ingameStats(Vector2f(INGAMESTATS_WIDTH, VIEW_HEIGHT)),
czoug1(Vector2f(40, 40))

{
	ingameStats.setOutlineColor(Color::White);
	ingameStats.setPosition(VIEW_WIDTH - INGAMESTATS_WIDTH, 0);
	czoug1.setFillColor(Color::Green);
	Vector2f cz1Position(50, 50);
	czoug1.setPosition(cz1Position);
	vector <Bullet> bullets;
	Vector2f bulletDirection(0.0f, -1.0f); // Domyœlny kierunek pocisków

}

Scene* Arena::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	if (Keyboard::isKeyPressed(Keyboard::E))
	{
		Vector2f bulletStartPos(czoug1.getPosition().x + czoug1.getSize().x / 2 - BulletSize / 2,
			czoug1.getPosition().y + czoug1.getSize().y / 2 - BulletSize / 2);

		bullets.emplace_back(bulletStartPos, bulletDirection);
	}
	return nullptr;
}

Scene* Arena::doCalculations(sf::RenderWindow& window, float deltaTime)
{


	deltaTime = clock.getElapsedTime().asSeconds();
	clock.restart();
	float velocity = 300 * deltaTime;
	Vector2f player1Pos = czoug1.getPosition();

	if (Keyboard::isKeyPressed(Keyboard::W) and !Keyboard::isKeyPressed(Keyboard::D) and !Keyboard::isKeyPressed(Keyboard::A))
	{
		player1Pos.y -= velocity;
		bulletDirection = Vector2f(0.0f, -1.0f);
		if (player1Pos.y < 0)
		{
			player1Pos.y = 0;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::A) and !Keyboard::isKeyPressed(Keyboard::D))
	{
		player1Pos.x -= velocity;
		bulletDirection = Vector2f(-1.0f, 0.0f);
		if (player1Pos.x < 0)
		{
			player1Pos.x = 0;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::S) and !Keyboard::isKeyPressed(Keyboard::D) and !Keyboard::isKeyPressed(Keyboard::A))
	{
		player1Pos.y += velocity;
		bulletDirection = Vector2f(0.0f, 1.0f);

		if (player1Pos.y + czoug1.getSize().y > VIEW_HEIGHT)
		{
			player1Pos.y = VIEW_HEIGHT - czoug1.getSize().y;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::D) and !Keyboard::isKeyPressed(Keyboard::A))
	{
		player1Pos.x += velocity;
		bulletDirection = Vector2f(1.0f, 0.0f);

		if (player1Pos.x + czoug1.getSize().x > VIEW_WIDTH - INGAMESTATS_WIDTH)
		{
			player1Pos.x = VIEW_WIDTH - INGAMESTATS_WIDTH - czoug1.getSize().x;
		}
	}

	czoug1.setPosition(player1Pos);

	for (auto& bullet : bullets)
	{
		bullet.shape.move(bullet.velocity);

		if (bullet.shape.getPosition().x < 0 || bullet.shape.getPosition().x > VIEW_WIDTH - INGAMESTATS_WIDTH ||
			bullet.shape.getPosition().y < 0 || bullet.shape.getPosition().y > VIEW_HEIGHT
			)
		{
			bullets.erase(bullets.begin());
		}
	
	}

	return nullptr;
}


void Arena::draw(sf::RenderWindow& window)
{
	window.draw(ingameStats);
	window.draw(czoug1);
	for (const auto& bullet : bullets)
	{
		window.draw(bullet.shape);
	}
}