#ifndef COLLIDEABLE_H__
#define COLLIDEABLE_H__

#include "CollisionBox.h"

class Collideable
{
public:
	/**
	 * Virtual functions that every collideable need to implement
	 *
	 */
	virtual CollisionBox* GetCollisionBox() = 0;
	virtual void Collision(CollisionBox*) = 0;
};

#endif