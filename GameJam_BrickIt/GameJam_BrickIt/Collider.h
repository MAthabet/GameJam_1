#pragma once
#include "Vector2d.h"
#include <iostream>

using namespace std;
class Collider
{
public:
	float r;
	Vector2d center;

	virtual bool checkCollision(Collider* other);
	virtual void updatePosition(Vector2d position);
	Collider(float r);
};

