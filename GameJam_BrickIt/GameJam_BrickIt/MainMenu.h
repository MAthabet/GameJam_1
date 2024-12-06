#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "ButtonsConfig.h"
#include "Animation.h"
#include "appConfjs.h"

class MainMenu
{
public:
	void start();
	bool loop(sf::RenderWindow* win);
	void close(sf::RenderWindow* win);
    bool gameOver(sf::RenderWindow* win, sf::View* defView);
	void draw(sf::RenderWindow* win);
	~MainMenu();
private:
	sf::Texture mainMenuTex;
	sf::Texture cursorTex;
    sf::Texture idle;
	sf::Sprite cursor;
	sf::Sprite mainMenu;
    sf::RectangleShape frame;
    Animation idleAnim;
	bool exit = false;

	Buttons buttonIsPressed(sf::Vector2f clkPos);
    Buttons buttonIsPressed(sf::Vector2f clkPos, bool a);
	 
};

