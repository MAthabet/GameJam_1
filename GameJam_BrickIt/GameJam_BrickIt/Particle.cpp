#include "Particle.h"

Particle::Particle(Vector2d postion)
{
	this->postion = postion;
	this->velocity = Vector2d(0, 0);
}

void Particle::Update(float dt)
{
	this->postion += this->velocity * dt;
	collider->updatePosition(this->postion);
}

