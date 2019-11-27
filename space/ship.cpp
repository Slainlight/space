#include "ship.h"

void Ship::rotation()
{
	static float mod = 0;
	float rotMod = mod / 5 + 1;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		convex.setRotation(convex.getRotation() - rotMod);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		convex.setRotation(convex.getRotation() + rotMod);
	}

	double xVel = sin(degreesToRadians(convex.getRotation()));
	double yVel = -cos(degreesToRadians(convex.getRotation()));

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (mod < 5)
			mod += 0.05;
	}
	else
	{
		if (mod > 0)
			mod -= 0.05;
		if (mod < 0)
			mod = 0;
	}

	convex.move(xVel * mod, yVel * mod);
}

void Ship::shoot()
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		double xVel = sin(degreesToRadians(convex.getRotation()));
		double yVel = -cos(degreesToRadians(convex.getRotation()));
	}

	//return Projectile();
}

void Ship::setPos(sf::Vector2f pos)
{
	convex.setPosition(pos);
}

sf::ConvexShape Ship::getDraw()
{
	rotation();
	shoot();
	return convex;
}
