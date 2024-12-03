#pragma once
#include "Vector2d.h"

class Collider
{
public:
	Vector2d ul;
	Vector2d lr;
	Vector2d position;

	void initCollider(Vector2d ul, Vector2d lr);
	void updatePosition(Vector2d position);
	bool checkCollision(Collider* other);
};

