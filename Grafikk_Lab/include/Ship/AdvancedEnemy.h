#ifndef ADVANCEDENEMY_H
#define ADVANCEDENEMY_H

#include "BaseShip.h"
#include "Bullet.h"

class AdvancedEnemy : public BaseShip {
public:
	AdvancedEnemy(Vector3D<float> position);
	virtual void Render();
	virtual void Shoot();
	virtual void Move();
	virtual bool CheckCollision(BaseShip *otShip);
	virtual bool CheckCollision(Bullet *aBullet);
	virtual bool CheckCollision(Vector3D<float> checkCol, int side);
	virtual void Update(float deltaTime);
protected:

};

#endif