#include "event.hpp"
#include "ship.hpp"
#include "rotation.hpp"
#include "asteroid.hpp"
#include "window.hpp"
#include "camera.hpp"
#include "generation.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

// Future TODO:
// - Camera Follow w/ Rotation (sorta done)
// - Projectiles w/ Collision (yikes)
// - Lots of foreseeable collision work...
// - Finish asteroid generation
// - Gravity functionality??
// - Get better memory utilization

int main()
{
#ifndef _DEBUG // Randomness
	srand(time(NULL));
#endif // !_DEBUG
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Space!", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	Ship player(30);
	player.setPos(Vector2f(5000, 5000));
	AsteroidCluster* test = new AsteroidCluster(Vector2f(0,0), Vector2f(10000, 10000));

	Camera c = Camera(player, window);

	while (window.isOpen())
	{
		Events(window);

		c.update();

		window.clear();
		//window.draw(player.getDraw());
		test->draw(window, player.getDraw());
		window.display();
	}

	delete test;
	return 0;
}
