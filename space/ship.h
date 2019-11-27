#pragma once
#include <SFML/Graphics.hpp>
#include "rotation.h"
#include "projectile.h"

using namespace sf;

class Ship
{
private:
	sf::ConvexShape convex;

public:
	Ship::Ship(float w, float ratio = 1.6)
	{
		//per 1 w, make 1.6 h
		float h = w * 1.6;

		// resize it to 5 points
		convex.setPointCount(4);

		// define the points
		convex.setPoint(0, sf::Vector2f(w / 2, 0.f));
		convex.setPoint(1, sf::Vector2f(0, h));
		convex.setPoint(2, sf::Vector2f(w / 2, h / 1.5));
		convex.setPoint(3, sf::Vector2f(w, h));

		//origin
		convex.setOrigin(w / 2, h / 2);

		//transparency
		convex.setFillColor(sf::Color(0,0,0,0));

		// set a 2-pixel wide orange outline
		convex.setOutlineThickness(2.f);
		convex.setOutlineColor(sf::Color(255, 255, 255));
	}
	void rotation();
	void shoot();
	void setPos(sf::Vector2f pos);
	sf::ConvexShape getDraw();
};