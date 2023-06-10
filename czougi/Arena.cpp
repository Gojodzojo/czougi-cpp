#include "Arena.h"
#include "Block.h"
#include "Level.h"
#include "Menu.h"
#include "Player.h"

#include<vector>

using namespace sf;
using namespace std;

const int INGAMESTATS_WIDTH = VIEW_WIDTH - VIEW_HEIGHT;  // obszar na statystki
const int PLAYER_SIZE = 2 * BLOCK_SIZE - 5;

//CO DO ZROBIENIA:
//- niszczenie bloku z cegły przez pocisk (cegla i pocisk znikaja)
//- zrobienie orłów 
//- po zniszczeniu czolg sie odradza
//- jak dany orzel zginie, to czolg sie nie odradza 




bool isColliding(Vector2f aPos, Vector2f aSize, Vector2f bPos, Vector2f bSize, float velocity, bool direction)
{
	if (direction)
		return aPos.x + velocity < bPos.x + bSize.x && aPos.x + aSize.x + velocity > bPos.x && aPos.y < bPos.y + bSize.y && aPos.y + aSize.y > bPos.y;
	else
		return aPos.x < bPos.x + bSize.x && aPos.x + aSize.x > bPos.x && aPos.y + velocity < bPos.y + bSize.y && aPos.y + aSize.y + velocity > bPos.y;
}


 

Arena::Arena(Level gameLevel) : level(gameLevel),
ingameStats(Vector2f(INGAMESTATS_WIDTH, VIEW_HEIGHT))
{

	ingameStats.setOutlineColor(Color::White);
	ingameStats.setPosition(VIEW_WIDTH - INGAMESTATS_WIDTH, 0);

	vector <Bullet> bullets;
	Vector2f bulletDirections; // domyślny kierunek pocisków

	Player p1(0);
	Player p2(1);
	p2.graphics.setPosition(700, 700);

	p1.graphics.setPosition(500, 500);

	level.players.push_back(p1);
	level.players.push_back(p2);

	BrickWall bw;
	bw.graphics.setPosition(300, 800);
	level.brickWalls.push_back(bw);
	BrickWall bw1;
	bw1.graphics.setPosition(400, 800);
	level.brickWalls.push_back(bw1);
	ConcreteWall cw;
	cw.graphics.setPosition(300, 600);
	level.concreteWalls.push_back(cw);
	ConcreteWall cw1;
	cw1.graphics.setPosition(400, 600);
	level.concreteWalls.push_back(cw1);
	Water w;
	w.graphics.setPosition(300, 400);
	level.Waters.push_back(w);
	Water w1;
	w1.graphics.setPosition(400, 400);
	level.Waters.push_back(w1);
	Leaves l;
	l.graphics.setPosition(300, 200);
	level.leaves.push_back(l);
	Leaves l1;
	l1.graphics.setPosition(400, 200);
	level.leaves.push_back(l1);
}

Scene* Arena::processEvent(sf::RenderWindow& window, sf::Event& event)
{

	for (int i = 0; i < level.players.size(); i++)
	{
		if (shootTimer[i] != 15)
			shootTimer[i]++;
		if (Keyboard::isKeyPressed(playersKeybindings[i].shot) && shootTimer[i] == 15)
		{
			Vector2f bulletStartPos(level.players[i].graphics.getPosition().x + level.players[i].graphics.getSize().x / 2 - BulletSize / 2,
				level.players[i].graphics.getPosition().y + level.players[i].graphics.getSize().y / 2 - BulletSize / 2);  // ustawienie pocisków na środku
			shootTimer[i] = 0;
			bullets[i].emplace_back(bulletStartPos, bulletDirections[i]);  //trzymanie w tablicy pozycji startowej i kierunku
		}

	}

	return nullptr;

}

Scene* Arena::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	deltaTime = clock.getElapsedTime().asSeconds();
	clock.restart();
	float velocity = 300 * deltaTime;


	for (int i = 0; i < level.players.size(); i++)
	{
		playerPositions[i] = level.players[i].graphics.getPosition();
	}

		




	for (int i = 0; i < level.players.size(); i++)
	{	

	if (Keyboard::isKeyPressed(playersKeybindings[i].up) and !Keyboard::isKeyPressed(playersKeybindings[i].down) and !Keyboard::isKeyPressed(playersKeybindings[i].right))
	{
		bulletDirections[i] = Vector2f(0.0f, -1.0f);
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.brickWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.brickWalls[j].graphics.getPosition(), level.brickWalls[j].graphics.getSize(), -velocity, 0))
				{
					playerPositions[i].y = level.brickWalls[j].graphics.getPosition().y + level.brickWalls[j].graphics.getSize().y + velocity;
				}
			}
		}

		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.concreteWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.concreteWalls[j].graphics.getPosition(), level.concreteWalls[j].graphics.getSize(), -velocity, 0))
				{
					playerPositions[i].y = level.concreteWalls[j].graphics.getPosition().y + level.concreteWalls[j].graphics.getSize().y + velocity;
				}
			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.Waters.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.Waters[j].graphics.getPosition(), level.Waters[j].graphics.getSize(), -velocity, 0))
				{
					playerPositions[i].y = level.Waters[j].graphics.getPosition().y + level.Waters[j].graphics.getSize().y + velocity;
				}
			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{

			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.players[j].graphics.getPosition(), level.players[j].graphics.getSize(), -velocity, 0) && i != j)
				{
					playerPositions[i].y = level.players[j].graphics.getPosition().y + level.players[j].graphics.getSize().y + velocity;
				}
			}
		}
		playerPositions[i].y -= velocity;
		if (playerPositions[i].y < 0)
		{
			playerPositions[i].y = 0;
		}

	}
	if (Keyboard::isKeyPressed(playersKeybindings[i].left) and !Keyboard::isKeyPressed(playersKeybindings[i].right))
	{
		bulletDirections[i] = Vector2f(-1.0f, 0.0f);

		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.brickWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.brickWalls[j].graphics.getPosition(), level.brickWalls[j].graphics.getSize(), -velocity, 1))
				{
					playerPositions[i].x = level.brickWalls[j].graphics.getPosition().x + level.brickWalls[j].graphics.getSize().x + velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.concreteWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.concreteWalls[j].graphics.getPosition(), level.concreteWalls[j].graphics.getSize(), -velocity, 1))
				{
					playerPositions[i].x = level.concreteWalls[j].graphics.getPosition().x + level.concreteWalls[j].graphics.getSize().x + velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.Waters.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.Waters[j].graphics.getPosition(), level.Waters[j].graphics.getSize(), -velocity, 1))
				{
					playerPositions[i].x = level.Waters[j].graphics.getPosition().x + level.Waters[j].graphics.getSize().x + velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{

			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.players[j].graphics.getPosition(), level.players[j].graphics.getSize(), -velocity, 1) && i != j)
				{
					playerPositions[i].x = level.players[j].graphics.getPosition().x + level.players[j].graphics.getSize().x + velocity;
				}
			}
		}
		playerPositions[i].x -= velocity;

		if (playerPositions[i].x < 0)
		{
			playerPositions[i].x = 0;
		}

	}

	if (Keyboard::isKeyPressed(playersKeybindings[i].down) and !Keyboard::isKeyPressed(playersKeybindings[i].right) and !Keyboard::isKeyPressed(playersKeybindings[i].left))
	{
		bulletDirections[i] = Vector2f(0.0f, 1.0f);


		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.brickWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.brickWalls[j].graphics.getPosition(), level.brickWalls[j].graphics.getSize(), velocity, 0))
				{
					playerPositions[i].y = level.brickWalls[j].graphics.getPosition().y - level.players[i].graphics.getSize().y - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.concreteWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.concreteWalls[j].graphics.getPosition(), level.concreteWalls[j].graphics.getSize(), velocity, 0))
				{
					playerPositions[i].y = level.concreteWalls[j].graphics.getPosition().y - level.players[i].graphics.getSize().y - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.Waters.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.Waters[j].graphics.getPosition(), level.Waters[j].graphics.getSize(), velocity, 0))
				{
					playerPositions[i].y = level.Waters[j].graphics.getPosition().y - level.players[i].graphics.getSize().y - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{

			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.players[j].graphics.getPosition(), level.players[j].graphics.getSize(), velocity, 0) && i != j)
				{
					playerPositions[i].y = level.players[j].graphics.getPosition().y - level.players[i].graphics.getSize().y - velocity;
				}
			}
		}
		playerPositions[i].y += velocity;
		if (playerPositions[i].y + level.players[i].graphics.getSize().y > VIEW_HEIGHT)
		{
			playerPositions[i].y = VIEW_HEIGHT - level.players[i].graphics.getSize().y;
		}

	}

	if (Keyboard::isKeyPressed(playersKeybindings[i].right) and !Keyboard::isKeyPressed(playersKeybindings[i].left))
	{
		bulletDirections[i] = Vector2f(1.0f, 0.0f);

		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.brickWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.brickWalls[j].graphics.getPosition(), level.brickWalls[j].graphics.getSize(), velocity, 1))
				{
					playerPositions[i].x = level.brickWalls[j].graphics.getPosition().x - level.players[i].graphics.getSize().x - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.concreteWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.concreteWalls[j].graphics.getPosition(), level.concreteWalls[j].graphics.getSize(), velocity, 1))
				{
					playerPositions[i].x = level.concreteWalls[j].graphics.getPosition().x - level.players[i].graphics.getSize().x - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.Waters.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.Waters[j].graphics.getPosition(), level.Waters[j].graphics.getSize(), velocity, 1))
				{
					playerPositions[i].x = level.Waters[j].graphics.getPosition().x - level.players[i].graphics.getSize().x - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{

			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.players[j].graphics.getPosition(), level.players[j].graphics.getSize(), velocity, 1) && i != j)
				{
					playerPositions[i].x = level.players[j].graphics.getPosition().x - level.players[i].graphics.getSize().x - velocity;
				}
			}
		}
		playerPositions[i].x += velocity;

		if (playerPositions[i].x + level.players[0].graphics.getSize().x > VIEW_WIDTH - INGAMESTATS_WIDTH)
		{
			playerPositions[i].x = VIEW_WIDTH - INGAMESTATS_WIDTH - level.players[0].graphics.getSize().x;
		}


	}


	level.players[i].graphics.setPosition(playerPositions[i]);
	
	
	int j = 0;
	for (auto& bullet : bullets[i])
	{
		cout << bullet.velocity.x << endl;
		cout << bullet.velocity.y << endl;
		if (bullet.velocity.x == 0 && bullet.velocity.y == 0)
		{
			bullet.shape.move(10.0f, 0);     //aby ustawić pierwszy pocisk musze znac rotacje czolgu 
		}
		else
		{
			bullet.shape.move(bullet.velocity);
		}
			

		if (bullet.shape.getPosition().x < 0 || bullet.shape.getPosition().x > VIEW_WIDTH - INGAMESTATS_WIDTH ||
			bullet.shape.getPosition().y < 0 || bullet.shape.getPosition().y > VIEW_HEIGHT
			)
		{
			bullets[i].erase(bullets[i].begin() + j); 
			j--;  //bo usuwam pocisk, to musze odjac aby wyrownac j z bullet
		}
		j++;
	}
	}
	return nullptr;
}




void Arena::draw(sf::RenderWindow& window)
{
	window.draw(ingameStats);

	for (int i = 0; i < level.players.size(); i++)
	{
		level.players[i].draw(window);
		for (const auto& bullet : bullets[i])
		{
			window.draw(bullet.shape);
		}
	}
	for (int i = 0; i < level.brickWalls.size(); i++)
		level.brickWalls[i].draw(window);
	for (int i = 0; i < level.concreteWalls.size(); i++)
		level.concreteWalls[i].draw(window);
	for (int i = 0; i < level.Waters.size(); i++)
		level.Waters[i].draw(window);
	for (int i = 0; i < level.leaves.size(); i++)
		level.leaves[i].draw(window);
}