#include "Collision/CollisionManager.h"

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

/**
 * Insert a new collideable to the list
 *
 */
void CollisionManager::AddCollideable(Collideable* collideable)
{
	_collideables.insert(collideable);	
}

/**
 * Remove a collideable from the list
 *
 */
void CollisionManager::RemoveCollideable(Collideable* collideable)
{
	_collideables.erase(collideable);
}

/**
 * This is where the magic happens with collision detection! 
 *
 */
void CollisionManager::CheckCollision()
{
	std::set<Collideable*>::iterator one = _collideables.begin();
	for(one; one != _collideables.end(); ++one)
	{
		std::set<Collideable*>::iterator two = _collideables.begin();
		for(two; two != _collideables.end(); ++two)
		{
			if(one == two)
				continue;

			if((*one)->GetCollisionBox()->Intersects(*(*two)->GetCollisionBox()))
			{
				(*one)->Collision((*two)->GetCollisionBox());
			}
		}
	}
}