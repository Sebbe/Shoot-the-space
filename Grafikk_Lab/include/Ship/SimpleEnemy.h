#ifndef SIMPLEENEMY_H
#define SIMPLEENEMY_H

#include "BaseShip.h"
#include "Bullet.h"

class SimpleEnemy : public BaseShip {
public:
	SimpleEnemy(Vector3D<float> position);
	virtual void Render();
	virtual void Shoot();
	virtual void Move();
	virtual CollisionBox* GetCollisionBox();
	virtual void Collision(CollisionBox*);
	virtual bool CheckCollision(Vector3D<float> checkCol, int side);
	virtual void Update(float deltaTime);
	virtual bool Delete();
	virtual void Active(bool isActive);
	bool ShouldDeActivate();
protected:
	bool _shouldDeActivate;
};

#endif