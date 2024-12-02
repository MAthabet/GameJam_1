#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"

class FallingItem {
private:
	void initVariables();

protected:
	float objPositionX = 0.f;
	float objPositionY = 0.f;
	float speed = 0.f;
	bool destroyed = false;
	ItemType objType;

	sf::RectangleShape shape;


public:
	FallingItem();
	FallingItem(ItemType type, float X_Position, float speed/*, sf::Sprite* temp*/);
	~FallingItem();

	void setObjPositionX(float x_pos);
	float getObjPositionX();
	float getObjPositionY();
	bool getDestroyedStatus() const;

	void updateObjPosY(float deltaTime);

	void draw(sf::RenderWindow& window, float deltaTime);
	void checkCollision();
	sf::Sprite* particle;
};