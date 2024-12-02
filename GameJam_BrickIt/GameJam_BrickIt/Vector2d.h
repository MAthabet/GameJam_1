#pragma once
#include <SFML/Graphics.hpp>

class Vector2d
{
public:
	float x;
	float y;

	Vector2d();
	Vector2d(float x, float y);
	Vector2d operator+(Vector2d other);
	Vector2d operator-(Vector2d other);
	Vector2d operator+=(Vector2d other);
	Vector2d operator-=(Vector2d other);
	Vector2d operator=(Vector2d other);
	bool operator==(Vector2d other);
	Vector2d operator*(float a);
	float operator*(Vector2d a);
	Vector2d operator/(float a);
	Vector2d operator*=(float a);
	float Dot(Vector2d other);
	float getMagnitude();
	Vector2d getNormalized();
	void normalize();
	operator sf::Vector2f();
	Vector2d getNormal();
};
