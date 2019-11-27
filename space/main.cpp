#include "event.h"
#include "ship.h"
#include "rotation.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

//Future TODO:
// - Camera Follow w/ Rotation
// - Projectiles w/ Collision
// - Astroids

int main()
{
	RenderWindow window(sf::VideoMode(1920, 1080), "Space!");
	window.setFramerateLimit(144);

	Ship player(30);
	player.setPos(Vector2f(50, 50));

	while (window.isOpen())
	{
		Events(window); 

		window.clear();
		window.draw(player.getDraw());
		window.display();
	}

	return 0;
}