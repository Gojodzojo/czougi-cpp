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


bool isColliding(Vector2f aPos, Vector2f aSize, Vector2f bPos, Vector2f bSize, float velocity, bool direction)
{
	if (direction)
		return aPos.x + velocity < bPos.x + bSize.x && aPos.x + aSize.x + velocity > bPos.x && aPos.y < bPos.y + bSize.y && aPos.y + aSize.y > bPos.y;
	else
		return aPos.x < bPos.x + bSize.x && aPos.x + aSize.x > bPos.x && aPos.y + velocity < bPos.y + bSize.y && aPos.y + aSize.y + velocity > bPos.y;
}

bool Arena::isCollidingWithBlocks(float velocity)
{
	for (int i = 0; i < level.players.size(); i++)
	{
		for (int j = 0; j < allBlocks.size(); j++)
		{
			if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), allBlocks[j].getPosition(), allBlocks[j].getSize(), -velocity, 0))
			{
				return false;
			}

		}
	}
}

 

Arena::Arena(Level gameLevel) : level(gameLevel),
ingameStats(Vector2f(INGAMESTATS_WIDTH, VIEW_HEIGHT))
{

	ingameStats.setOutlineColor(Color::White);
	ingameStats.setPosition(VIEW_WIDTH - INGAMESTATS_WIDTH, 0);

	vector <Bullet> bullets;
	Vector2f bulletDirection(0.0f, -1.0f); // domyślny kierunek pocisków
	shootTimer = 0;

	Player p1(0);
	Player p2(1);
	p2.graphics.setPosition(700, 700);

	p1.graphics.setPosition(500, 500);
	/*Player p2(1);
	p2.graphics.setPosition(600, 600);*/
	level.players.push_back(p1);
	level.players.push_back(p2);
	/*level.players.push_back(p2);*/
	//Keybindings k1(Keyboard::W, Keyboard::S, Keyboard::A, Keyboard::D, Keyboard::E);
	//Keybindings k2(Keyboard::Up, Keyboard::Down, Keyboard::Left, Keyboard::Right, Keyboard::Space);*/
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

	for (auto& block : level.brickWalls)
	{
		allBlocks.push_back(block.graphics);
	}

	for (auto& block : level.Waters)
	{
		allBlocks.push_back(block.graphics);
	}
	for (auto& block : level.concreteWalls)
	{
		allBlocks.push_back(block.graphics);
	}



}

Scene* Arena::processEvent(sf::RenderWindow& window, sf::Event& event)
{

	if (shootTimer <= 15)
		shootTimer++;

	if (Keyboard::isKeyPressed(Keyboard::E) and shootTimer >= 15)
	{
		Vector2f bulletStartPos(level.players[0].graphics.getPosition().x + level.players[0].graphics.getSize().x / 2 - BulletSize / 2,
			level.players[0].graphics.getPosition().y + level.players[0].graphics.getSize().y / 2 - BulletSize / 2);  // ustawienie pocisków na środku
		shootTimer = 0;
		bullets.emplace_back(bulletStartPos, bulletDirection);  //trzymanie w tablicy pozycji startowej i kierunku
	}


	return nullptr;

}

Scene* Arena::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	deltaTime = clock.getElapsedTime().asSeconds();
	clock.restart();
	float velocity = 300 * deltaTime;

	Vector2f player1Pos = level.players[0].graphics.getPosition();
	Vector2f player2Pos = level.players[1].graphics.getPosition();
	for (int i = 0; i < level.players.size(); i++)
		playerPositions[i] = level.players[i].graphics.getPosition();
	for (int i = 0; i < level.players.size(); i++)
	{
	if (Keyboard::isKeyPressed(playersKeybindings[i].up) and !Keyboard::isKeyPressed(playersKeybindings[i].down) and !Keyboard::isKeyPressed(playersKeybindings[i].right))
	{
		cout << i << ": " << playersKeybindings[i].up << endl;
		cout << Keyboard::Up << endl;
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
		playerPositions[i].y -= velocity;
		if (playerPositions[i].y < 0)
		{
			playerPositions[i].y = 0;
		}

	}
	if (Keyboard::isKeyPressed(playersKeybindings[i].left) and !Keyboard::isKeyPressed(playersKeybindings[i].right))
	{
		bulletDirection = Vector2f(-1.0f, 0.0f);

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
		playerPositions[i].x -= velocity;

		if (playerPositions[i].x < 0)
		{
			playerPositions[i].x = 0;
		}

	}

	if (Keyboard::isKeyPressed(playersKeybindings[i].down) and !Keyboard::isKeyPressed(playersKeybindings[i].right) and !Keyboard::isKeyPressed(playersKeybindings[i].left))
	{
		bulletDirection = Vector2f(0.0f, 1.0f);


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
		playerPositions[i].y += velocity;
		if (playerPositions[i].y + level.players[i].graphics.getSize().y > VIEW_HEIGHT)
		{
			playerPositions[i].y = VIEW_HEIGHT - level.players[i].graphics.getSize().y;
		}

	}

	if (Keyboard::isKeyPressed(playersKeybindings[i].right) and !Keyboard::isKeyPressed(playersKeybindings[i].left))
	{
		bulletDirection = Vector2f(1.0f, 0.0f);

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
		playerPositions[i].x += velocity;

		if (playerPositions[i].x + level.players[0].graphics.getSize().x > VIEW_WIDTH - INGAMESTATS_WIDTH)
		{
			playerPositions[i].x = VIEW_WIDTH - INGAMESTATS_WIDTH - level.players[0].graphics.getSize().x;
		}


	}

	level.players[i].graphics.setPosition(playerPositions[i]);
	
	}

	for (auto& bullet : bullets)
	{
		bullet.shape.move(bullet.velocity);

		if (bullet.shape.getPosition().x < 0 || bullet.shape.getPosition().x > VIEW_WIDTH - INGAMESTATS_WIDTH ||
			bullet.shape.getPosition().y < 0 || bullet.shape.getPosition().y > VIEW_HEIGHT
			)
		{
			bullets.erase(bullets.begin());   // pociski do poprawy
		}

	}
	return nullptr;
}




void Arena::draw(sf::RenderWindow& window)
{
	window.draw(ingameStats);

	for (int i = 0; i < level.players.size(); i++)
		level.players[i].draw(window);



	for (const auto& bullet : bullets)
	{
		window.draw(bullet.shape);
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