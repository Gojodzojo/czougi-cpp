#include "textures.h"

using namespace std;
using namespace sf;

sf::Texture* yellowTankTexture;
sf::Texture* blueTankTexture;
sf::Texture* greenTankTexture;
sf::Texture* redTankTexture;

sf::Texture* yellowEagleTexture;
sf::Texture* blueEagleTexture;
sf::Texture* greenEagleTexture;
sf::Texture* redEagleTexture;

sf::Texture* brickWallTexture;
sf::Texture* concreteWallTexture;
sf::Texture* waterTexture;
sf::Texture* leavesTexture;

Texture* eraserTexture;

void loadTextures()
{
	yellowTankTexture = loadTexture("yellow-tank.png");
	blueTankTexture = loadTexture("blue-tank.png");
	greenTankTexture = loadTexture("green-tank.png");
	redTankTexture = loadTexture("red-tank.png");

	yellowEagleTexture = loadTexture("yellow-eagle.png");
	blueEagleTexture = loadTexture("blue-eagle.png");
	greenEagleTexture = loadTexture("green-eagle.png");
	redEagleTexture = loadTexture("red-eagle.png");

	brickWallTexture = loadTexture("brick-wall.png");
	concreteWallTexture = loadTexture("concrete-wall.png");
	waterTexture = loadTexture("water.png");
	leavesTexture = loadTexture("leaves.png");

	eraserTexture = loadTexture("eraser.png");
}

Texture* loadTexture(const char* fileName)
{
	Texture* t = new Texture();

	if (!t->loadFromFile(string() + "images/" + fileName))
	{
		throw runtime_error(string() + "Could not load " + fileName);
	}

	return t;
}