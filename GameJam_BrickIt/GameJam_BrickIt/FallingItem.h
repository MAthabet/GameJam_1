#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "Constants.h"

class FallingItem {
private:

protected:
	bool destroyed = false;

public:
	FallingItem(ItemType type, sf::Sprite sprite);
	void update(float deltaTime);
	void moveTo(Vector2d a);
	~FallingItem();

	ItemType objType;
	sf::Sprite sprite;
	Particle particle;
};