#pragma once
#include "asteroid.h"
#include "window.h"
class AsteroidCluster
{
private:
	const static int totalAstroids = 200;
	Asteroid collection[totalAstroids];
	Vector2f origin;
	Vector2f size;

public:
	AsteroidCluster(Vector2f o, Vector2f s);
	void createAllRandomizedAsteroids();
	void draw(RenderWindow& w, sf::ConvexShape p);
	void addAstroid(Asteroid a);
	Asteroid generate();
};

