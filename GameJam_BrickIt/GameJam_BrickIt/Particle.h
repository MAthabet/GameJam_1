#pragma once
#include "Vector2d.h"
#include "Collider.h"

class Particle
{
public:
	Vector2d postion;
	Vector2d velocity;

	Collider* collider;

	Particle(Vector2d postion);
	void Update(float dt);
};