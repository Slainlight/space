#include "event.hpp"

void Events(sf::RenderWindow& w)
{
	sf::Event event;
	while (w.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			w.close();
	}
}
