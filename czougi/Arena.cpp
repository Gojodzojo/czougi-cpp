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
	ingameStats.setPosition(VIEW_WIDTH-INGAMESTATS_WIDTH, 0);
	czoug1.setFillColor(Color::Green);
	Vector2f cz1Position(50, 50);
	czoug1.setPosition(cz1Position); 
	//Vector2f player1Pos = czoug1.getPosition();
	vector<CircleShape> Bullets;
	bullet.setFillColor(Color::Red);
	bullet.setRadius(8.f);

}

Scene* Arena::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	return nullptr;
}

Scene* Arena::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	
	deltaTime = clock.getElapsedTime().asSeconds();
	clock.restart();
	float velocity = 300 * deltaTime;
	Vector2f player1Pos = czoug1.getPosition();
	char lastMove = 'C';

	std::vector<Vector2f> moveDirs;
	Vector2f moveDir;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player1Pos.y -= velocity;
		if (player1Pos.y < 0)
		{
			player1Pos.y = 0;
		}
		lastMove = 'W';
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player1Pos.x -= velocity;

		if (player1Pos.x < 0)
		{
			player1Pos.x = 0;
		}
		lastMove = 'A';
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player1Pos.y += velocity;

		if (player1Pos.y + czoug1.getSize().y > VIEW_HEIGHT)
		{
			player1Pos.y = VIEW_HEIGHT - czoug1.getSize().y;
		}
		lastMove = 'S';
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player1Pos.x += velocity;

		if (player1Pos.x + czoug1.getSize().x > VIEW_WIDTH - INGAMESTATS_WIDTH)
		{
			player1Pos.x = VIEW_WIDTH - INGAMESTATS_WIDTH - czoug1.getSize().x;
		}
		lastMove = 'D';
	}
	czoug1.setPosition(player1Pos);

	if (bulletTimer < 15)
		bulletTimer++;

	if (Keyboard::isKeyPressed(Keyboard::E) && bulletTimer == 15 )
	{
		cout << lastMove << endl;
		if (lastMove == 'W')
			moveDir = Vector2f(0.f, -3.f);
		else if(lastMove =='S')
			moveDir = Vector2f(0.f, 3.f);
		moveDirs.push_back(moveDir);
		cout << moveDir.x << ", " << moveDir.y << "\nSize = " << moveDirs.size() << endl;
		bullet.setPosition(player1Pos + Vector2f(50 / 4, 50 / 4));
		Bullets.push_back(bullet);

		bulletTimer = 0;
	}
	/*
	for (int i = 0; i < Bullets.size(); i++)
	{
		Bullets[i].move(0.f, -3.f);
		if (Bullets[i].getPosition().y <= 0)
			Bullets.erase(Bullets.begin() + i);
	}
	*/
	for (int i = 0; i < Bullets.size(); i++)
	{
		cout << moveDirs.size() << endl;
		Bullets[i].move(0.f,-3.f);
		//Bullets[i].move(moveDirs[i]);
		if (Bullets[i].getPosition().y <= 0)
			Bullets.erase(Bullets.begin() + i);
	}

	/*
	if (lastMove == 'W') {

		for (int i = 0; i < Bullets.size(); i++)
		{
			Bullets[i].move(0.f, -3.f);
			if (Bullets[i].getPosition().y <= 0)
				Bullets.erase(Bullets.begin() + i);
		}
	}

	else if (lastMove == 'S')
	{
		for (int i = 0; i < Bullets.size(); i++)
		{
			Bullets[i].move(0.f, 3.f);
			if (Bullets[i].getPosition().y >= VIEW_HEIGHT)
				Bullets.erase(Bullets.begin() + i);
		}
		
	}
	*/

	

	return nullptr;
}


void Arena::draw(sf::RenderWindow& window)
{
	window.draw(ingameStats);
	for (const auto& bullet : Bullets)
	{
		window.draw(bullet);
	}
	window.draw(czoug1);
}