#include "event.h"
#include "ship.h"
#include "rotation.h"
#include "asteroid.h"
#include "window.h"
#include "camera.h"
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

int main()
{
#ifndef _DEBUG // Randomness
	srand(time(NULL));
#endif // !_DEBUG
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Space!", sf::Style::Default, settings);
	window.setFramerateLimit(144);

	Ship player(30);

	Camera c = Camera(player, window);

	while (window.isOpen())
	{
		Events(window);

		c.update();

		window.clear();
		window.draw(player.getDraw());
		window.draw(asteroidTest(80).body);
		window.display();
	}

	return 0;
}