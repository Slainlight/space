#pragma once
#include <SFML/Graphics.hpp>
#include "ship.hpp"
#include "window.hpp"

using namespace sf;

class Camera
{
public:
	Ship* player;
	RenderWindow* window;

	Camera(Ship& p, RenderWindow& w);

	void update();
};
