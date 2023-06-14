#include "Bullet.h"

using namespace std;
using namespace sf;

Bullet::Bullet(const Vector2f& startPos, const Vector2f& direction)
{
    shape.setSize(sf::Vector2f(BulletSize, BulletSize));
    shape.setFillColor(sf::Color::Magenta);
    shape.setPosition(startPos);
    velocity = direction * BulletSpeed;
}