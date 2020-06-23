#include "asteroid.hpp"

Asteroid::Asteroid(double s)
{
	int totalPoints = 16;
	size = s;

	// random velocity
	randomVel.x = (rand() % 30) - 15;
	randomVel.y = (rand() % 30) - 15;

	// s for size
	body.setPointCount(totalPoints);

	// Define the points
	for (int i = 0; i < totalPoints; i++)
	{
		// Portion of unit circle
		double angle = ((double)(i)+1) / totalPoints * 2 * PI;
		double variability = (rand() % (int)s / 2) + s;

		// Using trig for circular points with variability
		body.setPoint(i, Vector2f(sin(angle) * variability, cos(angle) * variability));
	}

	// Temporary for visibility
	body.setPosition(Vector2f(200, 200));
	
	// Set Drawing Properties
	body.setOutlineThickness(s / 20 + 1);
	body.setOutlineColor(Color(255, 255, 255));

	// Transparency is cool
	body.setFillColor(Color(0, 0, 0, 255));
}

void Asteroid::setPos(Vector2f loc)
{
	body.setPosition(loc);
}

// All temporary for tests!
Asteroid asteroidTest(float size)
{
	// Test for asteroid drawing
	static bool single = true;
	static Asteroid test(size);

	// Trying variation with new objects
	if (Keyboard::isKeyPressed(Keyboard::R) && single == true)
	{
		test = Asteroid(size);
		single = false;
	}
	else if (!Keyboard::isKeyPressed(Keyboard::R))
	{
		single = true;
	}

	return test;
}
