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
	virtual CollisionBox* GetCollisionBox();
	virtual void Collision(CollisionBox*);
	virtual bool CheckCollision(Vector3D<float> checkCol, int side);
	virtual void Update(float deltaTime);
	virtual bool Delete();
	virtual void Active(bool isActive);
	void SetBulletpool(Bulletpool *manager);
	bool ShouldDeActivate();

	float GenerateRandomFloat(float maxNum, float minNum, bool minNegative = false)
		{
			if(minNegative)
				maxNum *= 100 * 2;
			else
				maxNum *= 100;

			minNum *= 100;
			int maxInt = static_cast<int>(maxNum);
			return (static_cast<float>(rand() % maxInt) + minNum) / 100;
		}
protected:
	bool _shouldDeActivate;
	Bulletpool *bulletpool;
	float shootTimer;
	float nextShoot;
};

#endif