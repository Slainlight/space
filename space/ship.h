#pragma once
#include <SFML/Graphics.hpp>
#include "rotation.h"

using namespace sf;

class Ship
{
private:
	ConvexShape body;

public:
	Ship::Ship(double w, double ratio = 1.6);
	void move();
	Vector2f shoot();
	void setPos(Vector2f pos);
	Vector2f getPos();
	double getRotation();
	ConvexShape getDraw();
};