#pragma once
#include <cmath>
#include "rotation.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class Asteroid
{
public:
	ConvexShape body;
	Vector2f randomVel;
	int size = 0;

	Asteroid() {}

	Asteroid(double s);

	void setPos(Vector2f loc);
};

Asteroid asteroidTest(float size);
