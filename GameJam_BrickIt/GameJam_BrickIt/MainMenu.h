#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
class MainMenu
{
public:
	void start();
	void loop(sf::RenderWindow* win);
	void close();
	void draw(sf::RenderWindow* win);
	~MainMenu();
private:
	sf::Texture mainMenuTex;
	sf::Texture cursorTex;
	sf::Sprite cursor;
	sf::Sprite mainMenu;
	 
};

