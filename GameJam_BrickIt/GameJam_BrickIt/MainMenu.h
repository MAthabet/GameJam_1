#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "ButtonsConfig.h"

class MainMenu
{
public:
	void start();
	bool loop(sf::RenderWindow* win);
	void close(sf::RenderWindow* win);
	void draw(sf::RenderWindow* win);
	~MainMenu();
private:
	sf::Texture mainMenuTex;
	sf::Texture cursorTex;
	sf::Sprite cursor;
	sf::Sprite mainMenu;
	bool exit = false;

	Buttons buttonIsPressed(sf::Vector2f clkPos);
	 
};

