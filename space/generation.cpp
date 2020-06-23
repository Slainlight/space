#include "generation.hpp"


AsteroidCluster::AsteroidCluster(Vector2f o, Vector2f s)
{
	origin = o;
	size = s;
	createAllRandomizedAsteroids();
}

void AsteroidCluster::draw(RenderWindow& w, sf::ConvexShape p)
{
	for (int i = 0; i < totalAstroids; i++)
	{ 
		collection[i].body.rotate(0.25*((float)i / (float)totalAstroids));
		w.draw(collection[i].body);
		
		collection[i].body.move(collection[i].randomVel.x/30, collection[i].randomVel.y / 30);

		if ((int)(totalAstroids / 2) == i)
			w.draw(p);
	}
		
}

//should move towards vectors later and probably will shift into a "AsteroidCluster" class
void AsteroidCluster::addAstroid(Asteroid a)
{
	static int count = 0;
	collection[count] = a;
	count++;
}

//incomplete asteroid generation
Asteroid AsteroidCluster::generate()
{
	Asteroid obj((double)(rand() % 80) + 20);
	Vector2f location;
	bool isAwayFromOthers = false;
	int trials = 0;

	location.x = (rand() % (int)size.x) + origin.x;
	location.y = (rand() % (int)size.y) + origin.y;
	obj.body.setPosition(location);

	return obj;
}

void AsteroidCluster::createAllRandomizedAsteroids()
{
	for(int i = 0; i < totalAstroids; i++)
		addAstroid(generate());
}
