#include "camera.hpp"

Camera::Camera(Ship& p, RenderWindow& w)
{
	player = &p;
	window = &w;
}

void Camera::update()
{
	static sf::View view(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(W_WIDTH, W_HEIGHT)));

	RenderWindow& w = *window;
	Ship& p = *player;

	if (Keyboard::isKeyPressed(Keyboard::PageUp))
	{
		view.zoom(1.01);
	}
	else if (Keyboard::isKeyPressed(Keyboard::PageDown))
	{
		view.zoom(0.99);
	}

	view.setCenter(p.getPos());
	w.setView(view);
}
