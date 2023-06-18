#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Block.h"

extern const int BLOCK_SIZE;

const sf::Vector2f TEXTURE_SCALE(BLOCK_SIZE / 512.0, BLOCK_SIZE / 512.0);

extern sf::Texture* yellowTankTexture;
extern sf::Texture* blueTankTexture;
extern sf::Texture* greenTankTexture;
extern sf::Texture* redTankTexture;

extern sf::Texture* yellowEagleTexture;
extern sf::Texture* blueEagleTexture;
extern sf::Texture* greenEagleTexture;
extern sf::Texture* redEagleTexture;

extern sf::Texture* brickWallTexture;
extern sf::Texture* concreteWallTexture;
extern sf::Texture* waterTexture;
extern sf::Texture* leavesTexture;

extern sf::Texture* eraserTexture;

extern sf::Texture* playIconTexture;
extern sf::Texture* saveIconTexture;
extern sf::Texture* deleteIconTexture;
extern sf::Texture* goBackIconTexture;

extern sf::Texture* tlo;
extern sf::Texture* Tytol;
extern sf::Texture* button1;
extern sf::Texture* button2;
extern sf::Texture* X;

void loadTextures();
sf::Texture* loadTexture(const char*);
