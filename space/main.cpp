#include "event.h"
#include "ship.h"
#include "rotation.h"
#include "asteroid.h"
#include "window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

// Future TODO:
// - Camera Follow w/ Rotation
// - Projectiles w/ Collision
// - Lots of foreseeable collision work...
// - Finish asteroid generation
// - Gravity functionality??

int main()
{
#ifndef _DEBUG //Randomness
	srand(time(NULL));
#endif // !_DEBUG

	RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Space!");
	window.setFramerateLimit(144);

	Ship player(30);

	while (window.isOpen())
	{
		Events(window);

		window.clear();
		window.draw(player.getDraw());
		window.draw(asteroidTest().body);
		window.display();
	}

	return 0;
}