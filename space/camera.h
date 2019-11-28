#pragma once
#include <SFML/Graphics.hpp>
#include "ship.h"
#include "window.h"

using namespace sf;

class Camera
{
public:
	Ship* player;
	RenderWindow* window;

	Camera(Ship& p, RenderWindow& w);

	void update();
};