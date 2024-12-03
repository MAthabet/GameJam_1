#pragma once
#include "Vector2d.h"
#include "Collider.h"
//#include "AABBCollider.h"

class Particle
{
	bool disableGiravity;
public:
	Vector2d postion;
	Vector2d velocity;
	Vector2d acceleration;
	Vector2d forces;
	Collider collider;

	float mass;
	float bounciness;
	Particle();
	void Update(float dt);
	void addForce(Vector2d force);
	void moveTo(Vector2d a);
	void bounce(float damping);
};