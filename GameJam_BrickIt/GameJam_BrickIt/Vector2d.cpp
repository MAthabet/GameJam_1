#include "Vector2d.h"

Vector2d::Vector2d()
{
	x = 0;
	y = 0;
}

Vector2d::Vector2d(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2d Vector2d::operator+(Vector2d other)
{

	return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator-(Vector2d other)
{
	return Vector2d(x - other.x, y - other.y);
}

Vector2d Vector2d::operator+=(Vector2d other)
{
	return Vector2d(x = x + other.x, y = y + other.y);
}

Vector2d Vector2d::operator-=(Vector2d other)
{
	return Vector2d(x = x - other.x, y = y - other.y);
}

Vector2d Vector2d::operator=(Vector2d other)
{
	return Vector2d(x = other.x, y = other.y);
}

bool Vector2d::operator==(Vector2d other)
{
	if (x == other.x)
		if (y == other.y)
			return true;
	return false;
}

Vector2d Vector2d::operator*(float a)
{
	return Vector2d(a * x, a * y);
}

float Vector2d::operator*(Vector2d a)
{
	return a.x * this->x + a.y * this->y;
}

Vector2d Vector2d::operator/(float a)
{
	return Vector2d(x / a, y / a);
}

Vector2d Vector2d::operator*=(float a)
{
	return Vector2d(x = a * x, x = a * y);
}

float Vector2d::Dot(Vector2d other)
{
	return x * other.x + y * other.y;
}

float Vector2d::getMagnitude()
{
	return sqrt(x * x + y * y);
}

Vector2d Vector2d::getNormalized()
{
	return Vector2d(x, y) / this->getMagnitude();
}

void Vector2d::normalize()
{
	x = x / this->getMagnitude();;
	y = y / this->getMagnitude();
}

Vector2d::operator sf::Vector2f()
{
	return sf::Vector2f(x, y);
}

Vector2d Vector2d::getNormal()
{
	return Vector2d(-y, x);
}
