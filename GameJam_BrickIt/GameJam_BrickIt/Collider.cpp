#include "Collider.h"

bool Collider::checkCollision(Collider* other)
{
    return (r + other->r) > (center - other->center).getMagnitude();
}

void Collider::updatePosition(Vector2d position)
{
    center = position;
}

Collider::Collider(float r)
{
    this->r = r;
}

