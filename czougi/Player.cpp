#include "Player.h"

using namespace sf;

Player::Player(PlayerColor playerColor): graphics(Vector2f(BLOCK_SIZE * 2, BLOCK_SIZE * 2))
{
	Color color = Color::Red;
	if (playerColor == 0)		color = Color::Yellow;
	else if (playerColor == 1)	color = Color::Blue;
	else if (playerColor == 2)	color = Color::Green;

	graphics.setFillColor(color);
}

void Player::draw(RenderWindow& window)
{
	window.draw(graphics);
}

Eagle::Eagle(PlayerColor playerColor) : graphics(Vector2f(BLOCK_SIZE * 2, BLOCK_SIZE * 2))
{
	Color color = Color::Red;
	if (playerColor == 0)		color = Color::Yellow;
	else if (playerColor == 1)	color = Color::Blue;
	else if (playerColor == 2)	color = Color::Green;

	graphics.setFillColor(color);
}

void Eagle::draw(RenderWindow& window)
{
	window.draw(graphics);
}