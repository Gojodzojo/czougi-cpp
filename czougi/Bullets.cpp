#include "Bullets.h"
#include "Scene.h"
#include <vector>

using namespace sf;

Bullets::Bullets(const Vector2f& startPos, const Vector2f& direction)
{
    shape.setSize(sf::Vector2f(BulletSize, BulletSize));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(startPos);
    velocity = direction * BulletSpeed;
}