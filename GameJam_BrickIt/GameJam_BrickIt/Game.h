#pragma once
#include <SFML/Graphics.hpp>


class Game
{
private:
	void init(sf::RenderWindow* win);
	void loop(sf::RenderWindow* win);
	void end(sf::RenderWindow* win);
	void draw(sf::RenderWindow* win);

public:
	bool run(sf::RenderWindow* win);

};

