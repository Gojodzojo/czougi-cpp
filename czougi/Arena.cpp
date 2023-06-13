#include "Arena.h"
#include "Block.h"
#include "Level.h"
#include "Menu.h"
#include "Player.h"
#include "Eagles.h"
#include<vector>

using namespace sf;
using namespace std;

const int INGAMESTATS_WIDTH = VIEW_WIDTH - VIEW_HEIGHT;  // obszar na statystki
const int PLAYER_SIZE = 2 * BLOCK_SIZE - 5;


//CO DO ZROBIENIA:
//- jak dany orzel zginie, to czolg sie nie odradza 
//- koniec gry gdy zostanie 1 orzeł zywy



bool isColliding(Vector2f aPos, Vector2f aSize, Vector2f bPos, Vector2f bSize, float velocity, bool direction)
{
	if (direction)
		return aPos.x + velocity < bPos.x + bSize.x && aPos.x + aSize.x + velocity > bPos.x && aPos.y < bPos.y + bSize.y && aPos.y + aSize.y > bPos.y;
	else
		return aPos.x < bPos.x + bSize.x && aPos.x + aSize.x > bPos.x && aPos.y + velocity < bPos.y + bSize.y && aPos.y + aSize.y + velocity > bPos.y;
}


bool bulletsColliding(RectangleShape bullet, RectangleShape block)
{
	FloatRect bounds1 = bullet.getGlobalBounds();
	FloatRect bounds2 = block.getGlobalBounds();
	return bounds1.intersects(bounds2);  //true jak sie nakladaja
 }

Arena::Arena(Level gameLevel) : level(gameLevel),
ingameStats(Vector2f(INGAMESTATS_WIDTH, VIEW_HEIGHT))
{

	ingameStats.setOutlineColor(Color::White);
	ingameStats.setPosition(VIEW_WIDTH - INGAMESTATS_WIDTH, 0);

	vector <Bullet> bullets;
	Vector2f bulletDirections; // domyślny kierunek pocisków
	vector <RectangleShape> tanksInGame;

	Player p1(0, Vector2f(700,700));
	Player p2(1, Vector2f(200,200));
	Player p3(2, Vector2f(500, 500));
	Player p4(3, Vector2f(50, 550));

	p1.graphics.setPosition(p1._startPos);
	p2.graphics.setPosition(p2._startPos);
	p3.graphics.setPosition(p3._startPos);
	p4.graphics.setPosition(p4._startPos);

	level.players.push_back(p1);
	level.players.push_back(p2);
	level.players.push_back(p3);
	level.players.push_back(p4);

	Eagle e1(0);
	Eagle e2(1);
	Eagle e3(2);
	Eagle e4(3);
	e1.graphics.setPosition(800, 800);
	e2.graphics.setPosition(100, 100);
	e3.graphics.setPosition(100, 800);
	e4.graphics.setPosition(800, 100);
	level.eagles.push_back(e1);
	level.eagles.push_back(e2);
	level.eagles.push_back(e3);
	level.eagles.push_back(e4);

	
	for (int i = 0; i < level.players.size(); i++)
	{
		level.players[i]._timeSinceDeath = 3.5;
	}
	

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
		if (Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].shot) && shootTimer[i] == 15 && level.players[i]._timeSinceDeath >= 3.5)
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
		playerPositions[i] = level.players[i].graphics.getPosition();
		

	for (int i = 0; i < level.eagles.size(); i++)
		eaglePositions[i] = level.eagles[i].graphics.getPosition();



	for (int i = 0; i < level.players.size(); i++)
	{	

	if (Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].up) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].down) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].right) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].left) && level.players[i]._timeSinceDeath >= 3.5)
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
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.players[j].graphics.getPosition(), level.players[j].graphics.getSize(), -velocity, 0) && i != j && level.players[j]._hasCollision)
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
		level.players[i].graphics.setPosition(playerPositions[i]);
	}
	if (Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].left) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].right) && level.players[i]._timeSinceDeath >= 3.5)
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
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.players[j].graphics.getPosition(), level.players[j].graphics.getSize(), -velocity, 1) && i != j && level.players[j]._hasCollision)
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
		level.players[i].graphics.setPosition(playerPositions[i]);
	}

	if (Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].down) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].right) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].left) && level.players[i]._timeSinceDeath >= 3.5 )
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
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.players[j].graphics.getPosition(), level.players[j].graphics.getSize(), velocity, 0) && i != j && level.players[j]._hasCollision)
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
		level.players[i].graphics.setPosition(playerPositions[i]);
	}

	if (Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].right) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i]._playerNumber].left) && level.players[i]._timeSinceDeath >= 3.5)
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
				if (isColliding(level.players[i].graphics.getPosition(), level.players[i].graphics.getSize(), level.players[j].graphics.getPosition(), level.players[j].graphics.getSize(), velocity, 1) && i != j && level.players[j]._hasCollision)
				{
					playerPositions[i].x = level.players[j].graphics.getPosition().x - level.players[i].graphics.getSize().x - velocity;
				}
			}
		}
		playerPositions[i].x += velocity;

		if (playerPositions[i].x + level.players[i].graphics.getSize().x > VIEW_WIDTH - INGAMESTATS_WIDTH)
		{
			playerPositions[i].x = VIEW_WIDTH - INGAMESTATS_WIDTH - level.players[i].graphics.getSize().x;
		}
		level.players[i].graphics.setPosition(playerPositions[i]);

	}


	//level.players[i].graphics.setPosition(playerPositions[i]);
	
	
	int j = 0;
	for (auto& bullet : bullets[i])
	{
		if (bullet.velocity.x == 0 && bullet.velocity.y == 0)
		{
			bullet.shape.move(10.0f, 0);     //aby ustawić pierwszy pocisk musze znac rotacje czolgu 
		}
		else
		{
			bullet.shape.move(bullet.velocity);
		}
			

		if ((bullet.shape.getPosition().x < 0 || bullet.shape.getPosition().x > VIEW_WIDTH - INGAMESTATS_WIDTH ||
			bullet.shape.getPosition().y < 0 || bullet.shape.getPosition().y > VIEW_HEIGHT)
			)
		{
			bullets[i].erase(bullets[i].begin() + j); 
			j--;  //bo usuwam pocisk, to musze odjac aby wyrownac j z bullet
		}
		else 
		{
			for (int k = 0; k < level.eagles.size(); k++)
			{
				if (bulletsColliding(bullet.shape, level.eagles[k].graphics))
				{
					if (level.eagles[k]._isAlive)
					{
						bullets[i].erase(bullets[i].begin() + j);
						j--;
					}
					if (level.players[i]._playerNumber != level.eagles[k]._playerNumber)
					{
						level.eagles[k]._isAlive = 0;
					}
				

				}
			}
			for (int k = 0; k < level.brickWalls.size(); k++)
			{
				if (bulletsColliding(bullet.shape, level.brickWalls[k].graphics))
				{
					level.brickWalls.erase(level.brickWalls.begin() + k);
					bullets[i].erase(bullets[i].begin() + j);
					j--;   
				}
				
			}

			for (int k = 0; k < level.concreteWalls.size(); k++)
			{
				if (bulletsColliding(bullet.shape, level.concreteWalls[k].graphics))
				{
					bullets[i].erase(bullets[i].begin() + j);
					j--;   
				}

			}



			for (int k = 0; k < level.players.size(); k++)
			{
				if (bulletsColliding(bullet.shape, level.players[k].graphics) && i != k && level.players[k]._timeSinceDeath >= 3.5)
				{
					level.players[k]._timeSinceDeath = 0;
					bullets[i].erase(bullets[i].begin() + j);
					j--;
					playerPositions[k] = level.players[k]._startPos; 
					level.players[k].graphics.setPosition(playerPositions[k]);
				}
			}
		}
		j++;
		//j = który pocisk
		//k =  ktory blok
		//level.players[i]._playerNumber].
	}
		if (level.eagles[i]._isAlive == 1)
		level.players[i]._timeSinceDeath += deltaTime;

	}
	int count = 0;
	for (int i = 0; i < level.players.size(); i++)
	{
		//if (level.eagles[i]._isAlive == 0)
		//	{
		//		count++;
		//		if (level.eagles.size() == 4)
		//		{
		//			if (count == 3)
		//			{
		//				if (level.eagles[0]._isAlive == 1)
		//					cout << "Wygral gracz 1" << endl;
		//				else if (level.eagles[1]._isAlive == 1)
		//					cout << "Wygral gracz 2" << endl;
		//				else if (level.eagles[2]._isAlive == 1)
		//					cout << "Wygral gracz 3" << endl;
		//				else if (level.eagles[3]._isAlive == 1)
		//					cout << "Wygral gracz 4" << endl;
		//			}
		//		}
		//		else if (level.eagles.size() == 2)
		//		{
		//				if (count == 1)
		//				{
		//					if (level.eagles[0]._isAlive == 1)
		//						cout << "Wygral gracz 1" << endl;
		//					else if (level.eagles[1]._isAlive == 1)
		//						cout << "Wygral gracz 2" << endl;
		//				}
		//		}
		//	}
		if (level.players[i]._isAlive == 0)
		{
			count++;
			if (count == (level.players.size() - 1))
				gameEnded = 1;
		}
		if(gameEnded && level.players[i]._isAlive)
			cout << "Wygral gracz: " << i + 1 << endl;
	}

	return nullptr;
}




void Arena::draw(sf::RenderWindow& window)
{
	window.draw(ingameStats);

	for (int i = 0; i < level.Waters.size(); i++)
		level.Waters[i].draw(window);
	for (int i = 0; i < level.eagles.size(); i++)
	{
		if (level.eagles[i]._isAlive==1)
			level.eagles[i].draw(window);
	}

	for (int i = 0; i < level.players.size(); i++)
	{
		if (level.players[i]._timeSinceDeath >= 3.5)
		{
			level.players[i].draw(window);
			level.players[i]._hasCollision = 1;
			for (const auto& bullet : bullets[i])
			{
				window.draw(bullet.shape);
			}
	
		}
		else
		{
			level.players[i]._hasCollision = 0;
			if(level.eagles[i]._isAlive == 0)
				level.players[i]._isAlive = 0;
		}
	}
	for (int i = 0; i < level.brickWalls.size(); i++)
		level.brickWalls[i].draw(window);
	for (int i = 0; i < level.concreteWalls.size(); i++)
		level.concreteWalls[i].draw(window);
	for (int i = 0; i < level.leaves.size(); i++)
		level.leaves[i].draw(window);
}
