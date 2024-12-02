#pragma once
#include "Particle.h"
//#include "Collider.h"

using namespace std;

class CollisionManager
{

private:
	std::vector<Particle*> particles;
public:
	void addParticle(Particle* particle);
	void Update(float deltaTime);
//void elasticCollision(Particle* i, Particle* j);

	static const Vector2d gravity;
};
