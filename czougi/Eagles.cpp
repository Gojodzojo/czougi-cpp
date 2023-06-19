#include "Eagles.h"


const int PLAYER_SIZE = 2 * BLOCK_SIZE - 5; // -5 by komfortowo sie poruszac miedzy blokami
using namespace sf;


Eagles::Eagles(int playerNumber) : graphics(Vector2f(BLOCK_SIZE * 2, BLOCK_SIZE * 2))
{
	Color playerColor = Color::Red;
	if (playerNumber == 0)		playerColor = Color::Yellow;
	else if (playerNumber == 1)	playerColor = Color::Blue;
	else if (playerNumber == 2)	playerColor = Color::Green;

	graphics.setFillColor(playerColor);
	_playerNumber = playerNumber;
}

void Eagles::draw(RenderWindow& window)
{
	window.draw(graphics);
}