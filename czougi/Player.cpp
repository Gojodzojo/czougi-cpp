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
	_startPos = startPos;
	_timeSinceDeath = 3.5;
	_hasCollision = 1;
	_isAlive = 1;
}

void Player::draw(RenderWindow& window)
{
	window.draw(graphics);
}

Texture* getEagleTexture(PlayerColor playerColor)
{
	if (playerColor == 0)		return yellowEagleTexture;
	if (playerColor == 1)		return blueEagleTexture;
	if (playerColor == 2)		return greenEagleTexture;
	return redEagleTexture;
}
	
Eagle::Eagle(PlayerColor playerColor) : graphics(*getEagleTexture(playerColor)), _isAlive(false)
{
	graphics.setScale(TEXTURE_SCALE);
	_isAlive = 1;
	_hasCollision = 1;
}

void Eagle::draw(RenderWindow& window)
{
	window.draw(graphics);
}