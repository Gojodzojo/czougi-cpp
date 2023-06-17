#include "Arena.h"
#include "Block.h"
#include "Level.h"
#include "Menu.h"
#include "Player.h"
#include "Eagles.h"
#include <vector>
#include"utils.h"
using namespace sf;
using namespace std;

const int INGAMESTATS_WIDTH = VIEW_WIDTH - VIEW_HEIGHT;  // obszar na statystki


bool isColliding(const Vector2f& aPos, const Vector2f& aSize, const Vector2f& bPos, const Vector2f& bSize, float velocity, bool direction)
{
	if (direction)
		return aPos.x + velocity < bPos.x + bSize.x && aPos.x + aSize.x + velocity > bPos.x && aPos.y < bPos.y + bSize.y && aPos.y + aSize.y > bPos.y;
	else
		return aPos.x < bPos.x + bSize.x && aPos.x + aSize.x > bPos.x && aPos.y + velocity < bPos.y + bSize.y && aPos.y + aSize.y + velocity > bPos.y;
}


bool bulletsColliding(const RectangleShape& bullet, const Vector2f& blockPosition, const Vector2f& blockSize)
{
	FloatRect bounds1 = bullet.getGlobalBounds();
	FloatRect bounds2 = FloatRect(blockPosition, blockSize);
	return bounds1.intersects(bounds2);  //true jak sie nakladaja
 }

Arena::Arena(Level gameLevel) : level(gameLevel),
ingameStats(Vector2f(INGAMESTATS_WIDTH, VIEW_HEIGHT)), iconPlayer1(*yellowTankTexture), iconPlayer2(*blueTankTexture), iconPlayer3(*greenTankTexture), iconPlayer4(*redTankTexture)
{
	ingameStats.setOutlineColor(Color::White);
	ingameStats.setPosition(VIEW_WIDTH - INGAMESTATS_WIDTH, 0);
	


	title.setFont(robotoRegular);
	title.setFillColor(Color::Black);
	title.setCharacterSize((VIEW_WIDTH - (INGAMESTATS_WIDTH / 2))* 0.03f); 
	title.setString(level.name);
	centerTextOrigin(title);
	title.setPosition(VIEW_WIDTH - (INGAMESTATS_WIDTH/2), BLOCK_SIZE);
	winnerText.setFont(robotoRegular);
	winnerText.setFillColor(Color::White);
	winnerText.setCharacterSize(120);



	


	backToMenu.setFont(robotoRegular);
	backToMenu.setFillColor(Color::White);
	backToMenu.setCharacterSize(50);
	backToMenu.setString("Nacisnij ESC aby wrocic do MENU");
	centerTextOrigin(backToMenu);
	if (level.players.size() >= 1)
	{
		iconPlayer1.setScale(TEXTURE_SCALE);
		iconPlayer1.setPosition(VIEW_WIDTH - (INGAMESTATS_WIDTH / 1.05), 125);
		numberOfDeathsP1.setPosition(VIEW_WIDTH - (INGAMESTATS_WIDTH / 1.35), 150);
		numberOfDeathsP1.setFillColor(Color::Yellow);
		numberOfDeathsP1.setOutlineColor(Color::Black);
		numberOfDeathsP1.setOutlineThickness(1.5f);
		numberOfDeathsP1.setFont(robotoRegular);
	}
	if (level.players.size() >= 2)
	{

		iconPlayer1.setTexture(*playersColors[level.players[0].playerColor]);
		numberOfDeathsP1.setFillColor(playersTextColors[level.players[0].playerColor]);
		iconPlayer2.setTexture(*playersColors[level.players[1].playerColor]);
		numberOfDeathsP2.setFillColor(playersTextColors[level.players[1].playerColor]);

		iconPlayer2.setScale(TEXTURE_SCALE);
		iconPlayer2.setPosition(VIEW_WIDTH - (INGAMESTATS_WIDTH / 1.05), 225);

		numberOfDeathsP2.setPosition(VIEW_WIDTH - (INGAMESTATS_WIDTH / 1.35), 250);
		numberOfDeathsP2.setOutlineColor(Color::Black);
		numberOfDeathsP2.setOutlineThickness(1.5f);
		numberOfDeathsP2.setFont(robotoRegular);
	}
	if (level.players.size() >= 3)
	{
		iconPlayer1.setTexture(*playersColors[level.players[0].playerColor]);
		numberOfDeathsP1.setFillColor(playersTextColors[level.players[0].playerColor]);
		iconPlayer2.setTexture(*playersColors[level.players[1].playerColor]);
		numberOfDeathsP2.setFillColor(playersTextColors[level.players[1].playerColor]);
		iconPlayer3.setTexture(*playersColors[level.players[2].playerColor]);
		numberOfDeathsP3.setFillColor(playersTextColors[level.players[2].playerColor]);

		iconPlayer3.setScale(TEXTURE_SCALE);
		iconPlayer3.setPosition(VIEW_WIDTH - (INGAMESTATS_WIDTH / 2), 125);

		numberOfDeathsP3.setPosition(VIEW_WIDTH - (INGAMESTATS_WIDTH / 3.4), 150);
		numberOfDeathsP3.setOutlineColor(Color::Black);
		numberOfDeathsP3.setOutlineThickness(1.5f);
		numberOfDeathsP3.setFont(robotoRegular);
	}
	if (level.players.size() == 4)
	{
		iconPlayer1.setTexture(*playersColors[level.players[0].playerColor]);
		numberOfDeathsP1.setFillColor(playersTextColors[level.players[0].playerColor]);
		iconPlayer2.setTexture(*playersColors[level.players[1].playerColor]);
		numberOfDeathsP2.setFillColor(playersTextColors[level.players[1].playerColor]);
		iconPlayer3.setTexture(*playersColors[level.players[2].playerColor]);
		numberOfDeathsP3.setFillColor(playersTextColors[level.players[2].playerColor]);
		iconPlayer4.setTexture(*playersColors[level.players[3].playerColor]);
		numberOfDeathsP4.setFillColor(playersTextColors[level.players[3].playerColor]);

		iconPlayer4.setScale(TEXTURE_SCALE);
		iconPlayer4.setPosition(VIEW_WIDTH - (INGAMESTATS_WIDTH / 2), 225);
		numberOfDeathsP4.setPosition(VIEW_WIDTH - (INGAMESTATS_WIDTH / 3.4), 250);
		numberOfDeathsP4.setOutlineColor(Color::Black);
		numberOfDeathsP4.setOutlineThickness(1.5f);
		numberOfDeathsP4.setFont(robotoRegular);
	}
	vector <Bullet> bullets;
	Vector2f bulletDirections; // domyślny kierunek pocisków

	
	for (int i = 0; i < level.players.size(); i++)
	{
		level.players[i]._timeSinceDeath = 3.5;
		level.players[i]._startPos = level.players[i].graphics.getPosition();
	}
}

Scene* Arena::processEvent(sf::RenderWindow& window, sf::Event& event)
{

	for (int i = 0; i < level.players.size(); i++)
	{
		if (shootTimer[i] != 15)
			shootTimer[i]++;
		if (Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].shot) && shootTimer[i] == 15 && level.players[i]._timeSinceDeath >= 3.5)
		{
			Vector2f bulletStartPos(level.players[i].graphics.getPosition().x + PLAYER_SIZE / 2 - BulletSize / 2,
				level.players[i].graphics.getPosition().y + PLAYER_SIZE / 2 - BulletSize / 2); // ustawienie pocisków na środku
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
	float velocity = 150 * deltaTime;
	for (int i = 0; i < level.players.size(); i++)
	{
		playerPositions[i] = level.players[i].graphics.getPosition();
		eaglePositions[i] = level.players[i].eagle.graphics.getPosition();
	}


	for (int i = 0; i < level.players.size(); i++)
	{	

	if (Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].up) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].down) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].right) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].left) && level.players[i]._timeSinceDeath >= 3.5)
	{
		level.players[i].graphics.setRotation(0.f);
		bulletDirections[i] = Vector2f(0.0f, -1.0f);
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.brickWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.brickWalls[j].graphics.getPosition(), BLOCK_SIZE_VEC, -velocity, 0))
				{
					playerPositions[i].y = level.brickWalls[j].graphics.getPosition().y + BLOCK_SIZE + velocity;
				}
			}
		}
		
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.concreteWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.concreteWalls[j].graphics.getPosition(), BLOCK_SIZE_VEC, -velocity, 0))
				{
					playerPositions[i].y = level.concreteWalls[j].graphics.getPosition().y + BLOCK_SIZE + velocity;
				}
			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.waters.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.waters[j].graphics.getPosition(), BLOCK_SIZE_VEC, -velocity, 0))
				{
					playerPositions[i].y = level.waters[j].graphics.getPosition().y + BLOCK_SIZE + velocity;
				}
			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{

			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.players[j].graphics.getPosition(), BLOCK_SIZE_VEC, -velocity, 0) && i != j && level.players[j]._hasCollision)
				{
					playerPositions[i].y = level.players[j].graphics.getPosition().y + BLOCK_SIZE_VEC.y + velocity;
				}
			}
		}

		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.players[j].eagle.graphics.getPosition(), EAGLE_SIZE_VEC, -velocity, 0) && level.players[j].eagle._hasCollision)
				{
					playerPositions[i].y = level.players[j].eagle.graphics.getPosition().y + EAGLE_SIZE + velocity;
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
	if (Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].left) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].right) && level.players[i]._timeSinceDeath >= 3.5)
	{
		level.players[i].graphics.setRotation(270.f);
		bulletDirections[i] = Vector2f(-1.0f, 0.0f);

		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.brickWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.brickWalls[j].graphics.getPosition(), BLOCK_SIZE_VEC, -velocity, 1))
				{
					playerPositions[i].x = level.brickWalls[j].graphics.getPosition().x + BLOCK_SIZE_VEC.x + velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.concreteWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.concreteWalls[j].graphics.getPosition(), BLOCK_SIZE_VEC, -velocity, 1))
				{
					playerPositions[i].x = level.concreteWalls[j].graphics.getPosition().x + BLOCK_SIZE_VEC.x + velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.waters.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.waters[j].graphics.getPosition(), BLOCK_SIZE_VEC, -velocity, 1))
				{
					playerPositions[i].x = level.waters[j].graphics.getPosition().x + BLOCK_SIZE_VEC.x + velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{

			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.players[j].graphics.getPosition(), BLOCK_SIZE_VEC, -velocity, 1) && i != j && level.players[j]._hasCollision)
				{
					playerPositions[i].x = level.players[j].graphics.getPosition().x + BLOCK_SIZE_VEC.x + velocity;
				}
			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.players[j].eagle.graphics.getPosition(), EAGLE_SIZE_VEC, -velocity, 1) && level.players[j].eagle._hasCollision)
				{
					playerPositions[i].x = level.players[j].eagle.graphics.getPosition().x + EAGLE_SIZE + velocity;
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

	if (Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].down) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].right) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].left) && level.players[i]._timeSinceDeath >= 3.5 )
	{
		bulletDirections[i] = Vector2f(0.0f, 1.0f);
		level.players[i].graphics.setRotation(180.f);

		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.brickWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.brickWalls[j].graphics.getPosition(), BLOCK_SIZE_VEC, velocity, 0))
				{
					playerPositions[i].y = level.brickWalls[j].graphics.getPosition().y - PLAYER_SIZE_VEC.y - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.concreteWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.concreteWalls[j].graphics.getPosition(), BLOCK_SIZE_VEC, velocity, 0))
				{
					playerPositions[i].y = level.concreteWalls[j].graphics.getPosition().y - PLAYER_SIZE_VEC.y - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.waters.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.waters[j].graphics.getPosition(), BLOCK_SIZE_VEC, velocity, 0))
				{
					playerPositions[i].y = level.waters[j].graphics.getPosition().y - PLAYER_SIZE_VEC.y - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{

			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.players[j].graphics.getPosition(), BLOCK_SIZE_VEC, velocity, 0) && i != j && level.players[j]._hasCollision)
				{
					playerPositions[i].y = level.players[j].graphics.getPosition().y - PLAYER_SIZE_VEC.y - velocity;
				}
			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.players[j].eagle.graphics.getPosition(), EAGLE_SIZE_VEC, velocity, 0) && level.players[j].eagle._hasCollision)
				{
					playerPositions[i].y = level.players[j].eagle.graphics.getPosition().y - PLAYER_SIZE_VEC.y - velocity;
				}

			}
		}
		playerPositions[i].y += velocity;
		if (playerPositions[i].y + PLAYER_SIZE_VEC.y > VIEW_HEIGHT)
		{
			playerPositions[i].y = VIEW_HEIGHT - PLAYER_SIZE_VEC.y;
		}
		level.players[i].graphics.setPosition(playerPositions[i]);
	}

	if (Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].right) and !Keyboard::isKeyPressed(playersKeybindings[level.players[i].playerColor].left) && level.players[i]._timeSinceDeath >= 3.5)
	{
		level.players[i].graphics.setRotation(90.f);
		bulletDirections[i] = Vector2f(1.0f, 0.0f);
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.brickWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.brickWalls[j].graphics.getPosition(), BLOCK_SIZE_VEC, velocity, 1))
				{
					playerPositions[i].x = level.brickWalls[j].graphics.getPosition().x - PLAYER_SIZE_VEC.x - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.concreteWalls.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.concreteWalls[j].graphics.getPosition(), BLOCK_SIZE_VEC, velocity, 1))
				{
					playerPositions[i].x = level.concreteWalls[j].graphics.getPosition().x - PLAYER_SIZE_VEC.x - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.waters.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.waters[j].graphics.getPosition(), BLOCK_SIZE_VEC, velocity, 1))
				{
					playerPositions[i].x = level.waters[j].graphics.getPosition().x - PLAYER_SIZE_VEC.x - velocity;
				}

			}
		}
		for (int i = 0; i < level.players.size(); i++)
		{

			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.players[j].graphics.getPosition(), BLOCK_SIZE_VEC, velocity, 1) && i != j && level.players[j]._hasCollision)
				{
					playerPositions[i].x = level.players[j].graphics.getPosition().x - PLAYER_SIZE_VEC.x - velocity;
				}
			}
		}

		for (int i = 0; i < level.players.size(); i++)
		{
			for (int j = 0; j < level.players.size(); j++)
			{
				if (isColliding(level.players[i].graphics.getPosition(), PLAYER_SIZE_VEC, level.players[j].eagle.graphics.getPosition(), EAGLE_SIZE_VEC, velocity, 1) && level.players[j].eagle._hasCollision)
				{
					playerPositions[i].x = level.players[j].eagle.graphics.getPosition().x - PLAYER_SIZE_VEC.x - velocity;
				}

			}
		}
		playerPositions[i].x += velocity;

		if (playerPositions[i].x + PLAYER_SIZE_VEC.x > VIEW_WIDTH - INGAMESTATS_WIDTH)
		{
			playerPositions[i].x = VIEW_WIDTH - INGAMESTATS_WIDTH - PLAYER_SIZE_VEC.x;
		}
		level.players[i].graphics.setPosition(playerPositions[i]);

	}

	
	
	int j = 0;
	for (auto& bullet : bullets[i])
	{
		if (bullet.velocity.x == 0 && bullet.velocity.y == 0)
		{
			bullet.shape.move(10.0f, 0);     //aby ustawić pierwszy pocisk musze znac rotacje czolgu DO ZROBIENIA jak beda grafiki
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
			for (int k = 0; k < level.players.size(); k++)
			{
				if (bulletsColliding(bullet.shape, level.players[k].eagle.graphics.getPosition(), EAGLE_SIZE_VEC))
				{
					if (level.players[k].eagle._isAlive)
					{
						bullets[i].erase(bullets[i].begin() + j);
						j--;
					}
					if (level.players[i].playerColor != level.players[k].playerColor)
					{
						level.players[k].eagle._isAlive = 0;
					}
				}
			}
			for (int k = 0; k < level.brickWalls.size(); k++)
			{
				if (bulletsColliding(bullet.shape, level.brickWalls[k].graphics.getPosition(), BLOCK_SIZE_VEC))
				{
					level.brickWalls.erase(level.brickWalls.begin() + k);
					if(j >= 0)
						bullets[i].erase(bullets[i].begin() + j);
					j--;   
				}
				
			}

			for (int k = 0; k < level.concreteWalls.size(); k++)
			{
				if (bulletsColliding(bullet.shape, level.concreteWalls[k].graphics.getPosition(), BLOCK_SIZE_VEC))
				{
					if (j >= 0)
						bullets[i].erase(bullets[i].begin() + j);
					j--;   
				}

			}

			for (int k = 0; k < level.players.size(); k++)
			{
				if (bulletsColliding(bullet.shape, level.players[k].graphics.getPosition(), PLAYER_SIZE_VEC) && i != k && level.players[k]._timeSinceDeath >= 3.5)
				{
					level.players[k]._timeSinceDeath = 0;
					bullets[i].erase(bullets[i].begin() + j);
					j--;
					playerPositions[k] = level.players[k]._startPos; 
					level.players[k].graphics.setPosition(playerPositions[k]);
					level.players[k].numberOfDeaths += 1;
				}
			}
		}
		j++;
		//j = który pocisk
		//k =  ktory blok
		//level.players[i].playerColor = ktory gracz.
	}
		if (level.players[i].eagle._isAlive == 1)
		level.players[i]._timeSinceDeath += deltaTime;

	}
	int count = 0;
	for (int i = 0; i < level.players.size(); i++)
	{
		if (level.players[i]._isAlive == 0)
		{
			count++;
			if (count == (level.players.size() - 1))
				gameEnded = 1;
		}
		if (gameEnded && level.players[i]._isAlive)
		{
			gameOver = 1;
			winnerText.setString("Wygral gracz " + to_string(i+1));
			winnerText.setFillColor(playersTextColors[level.players[i].playerColor]);
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				return new Menu;
			}
		}


	if (level.players.size() >= 1)
		numberOfDeathsP1.setString(to_string(level.players[0].numberOfDeaths));
	 if (level.players.size() >= 2)
		numberOfDeathsP2.setString(to_string(level.players[1].numberOfDeaths));
	 if (level.players.size() >= 3)
		numberOfDeathsP3.setString(to_string(level.players[2].numberOfDeaths));
	if (level.players.size() == 4)
		numberOfDeathsP4.setString(to_string(level.players[3].numberOfDeaths));

	centerTextOrigin(numberOfDeathsP1);
	centerTextOrigin(numberOfDeathsP2);
	centerTextOrigin(numberOfDeathsP3);
	centerTextOrigin(numberOfDeathsP4);



	}
	return nullptr;
}




void Arena::draw(sf::RenderWindow& window)
{
	window.draw(ingameStats);
	window.draw(title);
	if (level.players.size() >= 1)
	{
		window.draw(iconPlayer1);
		window.draw(numberOfDeathsP1);
	}
	if (level.players.size() >= 2)
	{
		window.draw(iconPlayer2);
		window.draw(numberOfDeathsP2);
	}
	if (level.players.size() >= 3)
	{
		window.draw(iconPlayer3);
		window.draw(numberOfDeathsP3);
	}
	if (level.players.size() == 4)
	{
		window.draw(iconPlayer4);
		window.draw(numberOfDeathsP4);
	}
	
	


	for (int i = 0; i < level.waters.size(); i++)
		level.waters[i].draw(window);
	for (int i = 0; i < level.players.size(); i++)
	{
		if (level.players[i].eagle._isAlive == 1)
		{
			level.players[i].eagle._hasCollision = 1;
			level.players[i].eagle.draw(window);
		}
		else
			level.players[i].eagle._hasCollision = 0;
	}

	for (int i = 0; i < level.players.size(); i++)
	{
		if (level.players[i]._timeSinceDeath >= 3.5)
		{
			level.players[i]._hasCollision = 1;
			for (const auto& bullet : bullets[i])
			{
				window.draw(bullet.shape);
			}
			level.players[i].draw(window);
	
		}
		else
		{
			level.players[i]._hasCollision = 0;
			if (level.players[i].eagle._isAlive == 0)
			{
				level.players[i]._isAlive = 0;
			}
		}
	}
	for (int i = 0; i < level.brickWalls.size(); i++)
		level.brickWalls[i].draw(window);
	for (int i = 0; i < level.concreteWalls.size(); i++)
		level.concreteWalls[i].draw(window);
	for (int i = 0; i < level.leaves.size(); i++)
		level.leaves[i].draw(window);
	if (gameOver == 1)
	{
		centerTextOrigin(winnerText);
		winnerText.setPosition((VIEW_WIDTH - INGAMESTATS_WIDTH) / 2, VIEW_HEIGHT / 2);
		backToMenu.setPosition((VIEW_WIDTH - INGAMESTATS_WIDTH) / 2, VIEW_HEIGHT / 2 + 100);
		window.draw(winnerText);
		window.draw(backToMenu);
	}
}
