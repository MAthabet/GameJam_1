#pragma once
#include <SFML/Graphics.hpp>


class Game
{
private:
	void init(sf::RenderWindow* win);
	void loop(sf::RenderWindow* win);
	bool end(sf::RenderWindow* win);

public:
	bool run(sf::RenderWindow* win);

};

