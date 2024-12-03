#include "Collider.h"

void Collider::initCollider(Vector2d ul, Vector2d lr)
{
	this->ul = ul;
	this->lr = lr;
	position = lr;
}

void Collider::updatePosition(Vector2d position)
{
	ul += position - this->position;
	lr += position - this->position;
	//printf("ul %f %f\nlr %f %f\npos %f %f\n----------------",ul.x,ul.y,lr.x,lr.y, position.x, position.y );
	this->position = position;
}

bool Collider::checkCollision(Collider* other)
{
	return !(ul.x > other->lr.x || ul.y > other->lr.y || lr.x < other->ul.x || lr.y < other->ul.y);
}
