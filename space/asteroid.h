#pragma once

#include "rotation.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Asteroid
{
public:
	ConvexShape body;
	int size = 0;

	Asteroid() {}

	Asteroid(double s);

	void setPos(Vector2f loc);
};

Asteroid asteroidTest();