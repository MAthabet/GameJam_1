#include "CollisionManager.h"

void CollisionManager::Update(float deltaTime)
{
	int size = items->size();
	for (int i = 0; i < size; i++)
	{
		(*items)[i].update(deltaTime);
		//check collision with ground
		if ((*items)[i].particle.postion.y >= PLATFORM_POSITION)
		{
			if (abs((*items)[i].particle.velocity.y) <= 1)
			{
				items->erase(items->begin() + i);
				i--;
				size--;
				continue;
			}
			(*items)[i].particle.postion.y = PLATFORM_POSITION;
			(*items)[i].particle.bounce(0.4);
			/*printf("%f %f", (*items)[i].particle.postion.x, (*items)[i].particle.postion.y);
			printf("s: %f %f\n", (*items)[i].sprite.getPosition().x, (*items)[i].sprite.getPosition().y);
			printf("s: %f %f\n---------\n", (*items)[i].sprite.getOrigin().x, (*items)[i].sprite.getOrigin().y);*/
			
		}
	}
}

int CollisionManager::checkCollisionWith(Collider* collider)
{
	int size = items->size();
	for (int i = 0; i < size; i++)
	{
		if (collider->checkCollision(&(*items)[i].particle.collider))
		{
			ItemType temp = (*items)[i].objType;
			items->erase(items->begin() + i);
			return temp;
		}
	}
	return -1;
}

CollisionManager::CollisionManager(std::vector<FallingItem>* items)
{
	this->items = items;
}
