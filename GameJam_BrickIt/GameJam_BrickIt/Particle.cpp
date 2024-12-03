#include "Particle.h"
#include "Constants.h"

Particle::Particle()
{
	this->velocity = this->acceleration = Vector2d(0, 0);
	this->forces = Vector2d(0, +9.8);
	this->mass = 1;
	this->bounciness = 0.3;
}

void Particle::Update(float dt)
{
	this->acceleration = this->forces / this->mass;
	this->velocity += this->acceleration * dt * FALLING_SPEED;
	this->postion += this->velocity * dt;
	collider.updatePosition(this->postion);
	if(!disableGiravity)
	this->forces.y = +9.8;
}

void Particle::addForce(Vector2d force)
{
	this->forces += force;
}

void Particle::bounce(float damping)
{
	if (std::abs(this->velocity.y) > 0.1f)
	{
		this->velocity.y *= -damping;
	}
	else
	{
		this->velocity.y = 0;
	}
}

void Particle::moveTo(Vector2d a)
{
	//collider.position = Vector2d(0,0);
	this->postion = a;
	collider.updatePosition(a);
}
