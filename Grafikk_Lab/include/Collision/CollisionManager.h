#ifndef COLLISION_MANAGER_H__
#define COLLISION_MANAGER_H__

#include <set>
#include <iostream>
#include "Collideable.h"

class CollisionManager
{
public:
	/**
		Constructer and destructer
	*/
	CollisionManager();
	~CollisionManager();

	/* Adds a collideable to the list of things that can collidate */
	void AddCollideable(Collideable* collideable);
	
	/* Removes a collideable from the list */
	void RemoveCollideable(Collideable* collideable);

	/* Checks collision for everything in the list */
	void CheckCollision();

private:
	/* Stores every collidable in a set */
	std::set<Collideable*> _collideables;
};

#endif