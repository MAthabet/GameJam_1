#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "constants.h"

class Player
{
	void move(float dt, int dir);
	bool isFlibbed = false;
	void invertInput();

public:
	int health = 5;
	int score = 0;
	sf::RectangleShape frame;
	Collider collider;
	bool isTripped = false;

	void updateCollider(sf::Vector2f pos);
	void handleInput();
	
};

