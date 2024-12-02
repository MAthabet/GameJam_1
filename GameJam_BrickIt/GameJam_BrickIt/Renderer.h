#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Renderer
{
private:
	std::list<sf::Sprite*> drawables;
public:
	void AddDrawable(sf::Sprite* drawable);
	void Render(sf::RenderWindow* window);
};
