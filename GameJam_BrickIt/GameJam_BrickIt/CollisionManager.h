#pragma once
#include "Particle.h"
#include "FallingItem.h"
//#include "Collider.h"

using namespace std;

class CollisionManager
{
private:
	void bouncyCollision(FallingItem* item);
	std::vector<FallingItem>* items;
public:
	//void addItem(FallingItem* item);
	void Update(float deltaTime);
	int checkCollisionWith(Collider* collider);
	CollisionManager(std::vector<FallingItem>* items);
};
