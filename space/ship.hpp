#pragma once
#include <cmath>
#include "rotation.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class Ship
{
private:
	ConvexShape body;

public:
	Ship(double w, double ratio = 1.6);
	void move();
	Vector2f shoot();
	void setPos(Vector2f pos);
	Vector2f getPos();
	double getRotation();
	ConvexShape getDraw();
};
