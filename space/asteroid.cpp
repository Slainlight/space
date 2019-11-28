#include "asteroid.h"

Asteroid::Asteroid(double s)
{
	int totalPoints = 16;
	size = s;

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

	// Transparency? Maybe? Nah for now
	body.setFillColor(Color(0, 0, 0, 255));
}

void Asteroid::setPos(Vector2f loc)
{
	body.setPosition(loc);
}

// All temporary for tests!
Asteroid asteroidTest()
{
	// Test for asteroid drawing
	static bool single = true;
	static Asteroid test(50);

	// Trying variation with new objects
	if (Keyboard::isKeyPressed(Keyboard::R) && single == true)
	{
		test = Asteroid(50);
		single = false;
	}
	else if (!Keyboard::isKeyPressed(Keyboard::R))
	{
		single = true;
	}

	return test;
}