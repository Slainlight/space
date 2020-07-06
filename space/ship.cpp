#include "ship.hpp"
#include "window.hpp"

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
	double timed = regulate.getElapsedTime().asSeconds();

	const double rotspeed = 200;
	double rotmod = rotspeed * timed;

	const double movespeed = 2000;
	double movemod = movespeed * timed;

	double xVel = sin(degreesToRadians(body.getRotation())) * movemod;
	double yVel = -cos(degreesToRadians(body.getRotation())) * movemod;

	if (Keyboard::isKeyPressed(Keyboard::Left))
		body.setRotation(body.getRotation() - rotmod);
	if (Keyboard::isKeyPressed(Keyboard::Right))
		body.setRotation(body.getRotation() + rotmod);
	if (Keyboard::isKeyPressed(Keyboard::Up))
		body.move(xVel, yVel);

	regulate.restart();
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
