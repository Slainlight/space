#pragma once
#include <SFML/Graphics.hpp>

class Projectile
{
private:
	float xVel = 0;
	float yVel = 0;
	sf::CircleShape shape;
public:
	Projectile(float size, sf::Vector2f velocity)
	{
		shape = sf::CircleShape(size, 8);
	}
	void move();
};