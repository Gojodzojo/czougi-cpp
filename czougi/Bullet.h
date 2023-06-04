#pragma once
#include"Scene.h"

const float BulletSize = 10.0f;
const float BulletSpeed = 10.0f;

class Bullet
{
public:

    sf::RectangleShape shape;
    sf::Vector2f velocity;

    Bullet(const sf::Vector2f& startPos, const sf::Vector2f& direction);
   
};

