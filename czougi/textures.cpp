#include "textures.h"

using namespace std;
using namespace sf;

Texture* yellowTankTexture;
Texture* blueTankTexture;
Texture* greenTankTexture;
Texture* redTankTexture;

Texture* yellowEagleTexture;
Texture* blueEagleTexture;
Texture* greenEagleTexture;
Texture* redEagleTexture;

Texture* brickWallTexture;
Texture* concreteWallTexture;
Texture* waterTexture;
Texture* leavesTexture;

Texture* eraserTexture;

Texture* playIconTexture;
Texture* saveIconTexture;
Texture* deleteIconTexture;

Texture* tlo;
Texture* Tytol;
Texture* button1;
Texture* button2;
Texture* X;

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

	playIconTexture = loadTexture("play-icon.png");
	saveIconTexture = loadTexture("save-icon.png");
	deleteIconTexture = loadTexture("delete-icon.png");

	tlo = loadTexture("t³o.jpg");
	Tytol = loadTexture("tytol.png");
	button1 = loadTexture("Button1.png");
	button2 = loadTexture("cog.png");
	X = loadTexture("X.png");
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