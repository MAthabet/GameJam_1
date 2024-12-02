#include "CollisionManager.h"

void CollisionManager::addParticle(Particle* particle)
{
	particles.push_back(particle);
}

void CollisionManager::Update(float deltaTime)
{
	int size = particles.size();
	for (int i = 0; i < size; i++)
	{
		particles[i]->Update(deltaTime);
		for (int j = i + 1; j < size; j++)
		{
			if (particles[i]->collider->checkCollision(particles[j]->collider))
			{
				printf("Collided");
				//elasticCollision(particles[i], particles[j]);
			}
		}
	}
}
//// final velocity afetr elastic collision
//Vector2d ecFinalVelocity(Vector2d vself, const float& mself, Vector2d vother, const float& mother)
//{
//	float mt = mself + mother;
//	return vself * ((mself - mother) / mt) + vother * (2 * mother / mt);
//}