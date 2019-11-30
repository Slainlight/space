#include "ship.h"
#include "window.h"

Ship::Ship(double w, double ratio)
{
	// For each w, make ratio h
	double h = w * ratio;

	// Resize it to 4 points
	body.setPointCount(4);

	// Define the points
	body.setPoint(0, Vector2f(w / 2, 0));
	body.setPoint(1, Vector2f(0, h));
	body.setPoint(2, Vector2f(w / 2, h / 1.5));
	body.setPoint(3, Vector2f(w, h));

	// Origin
	body.setOrigin(w / 2, h / 2);

	// Transparency
	body.setFillColor(Color(255, 255, 255, 255));

	// Set a 3-pixel wide white outline
	body.setOutlineThickness(3.f);
	body.setOutlineColor(Color(255, 255, 255));

	// Set starting position
	setPos(Vector2f(W_WIDTH / 2, W_HEIGHT / 2));
}

void Ship::move()
{
	static double mod = 0;
	double rotMod = mod / 5 + 0.5;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		body.setRotation(body.getRotation() - rotMod);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		body.setRotation(body.getRotation() + rotMod);
	}

	// directional velocities
	double xVel = sin(degreesToRadians(body.getRotation()));
	double yVel = -cos(degreesToRadians(body.getRotation()));

	// acceleration
	const static double accelerationSpeed = 0.05;
	const static double maxMod = 5;

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (mod < maxMod)
			mod += accelerationSpeed;
	}
	else
	{
		if (mod > 0)
			mod -= accelerationSpeed;
		if (mod < 0)
			mod = 0;
	}

	if (!Keyboard::isKeyPressed(Keyboard::Down))
	{
		body.move(xVel * mod, yVel * mod);
	}
	else
	{
		body.move(-xVel, -yVel);
		mod = 0;
	}
}

Vector2f Ship::shoot()
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		double xVel = sin(degreesToRadians(body.getRotation()));
		double yVel = -cos(degreesToRadians(body.getRotation()));

		return Vector2f(xVel, yVel);
	}

	return Vector2f(0, 0);
}

void Ship::setPos(Vector2f pos)
{
	body.setPosition(pos);
}

Vector2f Ship::getPos()
{
	return body.getPosition();
}

double Ship::getRotation()
{
	return (double)body.getRotation();
}

ConvexShape Ship::getDraw()
{
	move();
	shoot();
	return body;
}
