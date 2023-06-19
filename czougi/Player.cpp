#include "Player.h"

using namespace sf;
	
Texture* getPlayerTexture(PlayerColor playerColor)
{
	if (playerColor == 0)		return yellowTankTexture;
	if (playerColor == 1)		return blueTankTexture;
	if (playerColor == 2)		return greenTankTexture;
	return redTankTexture;
}

Player::Player(PlayerColor playerColor, Vector2f startPos) : 
	graphics(*getPlayerTexture(playerColor)),
	playerColor(playerColor),
	eagle(playerColor)
{
	graphics.setScale(TEXTURE_SCALE);
	graphics.setOrigin(512, 512);
	startPos = startPos;
	timeSinceDeath = 3.5;
	hasCollision = 1;
	isAlive = 1;
	int numberOfDeaths = 0;

}

void Player::draw(RenderWindow& window)
{
	graphics.move(BLOCK_SIZE_VEC);
	window.draw(graphics);
	graphics.move(-BLOCK_SIZE_VEC);
}

Texture* getEagleTexture(PlayerColor playerColor)
{
	if (playerColor == 0)		return yellowEagleTexture;
	if (playerColor == 1)		return blueEagleTexture;
	if (playerColor == 2)		return greenEagleTexture;
	return redEagleTexture;
}
	
Eagle::Eagle(PlayerColor playerColor) : graphics(*getEagleTexture(playerColor))
{
	graphics.setScale(TEXTURE_SCALE);
	isAlive = 1;
	hasCollision = 1;
}

void Eagle::draw(RenderWindow& window)
{
	window.draw(graphics);
}