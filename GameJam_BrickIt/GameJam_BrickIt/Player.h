#pragma once
#include <SFML/Graphics.hpp>

class Player
{

public:
	int health = 5;
	int dirction;
	sf::Vector2f position;
	bool flipping = false;
	bool died = false;
	sf::Sprite sprite;
	sf::RectangleShape shape;
	void initVariables() {
		position.x = 500;
		position.y = 400;
		shape.setFillColor(sf::Color::White);
		shape.setPosition(position);
		shape.setSize(sf::Vector2f(30, 30));
	}
	void move(float dt, int dir);
	void updateHealth(bool isCollided);
	bool isFlipping(int dir);
	
};

