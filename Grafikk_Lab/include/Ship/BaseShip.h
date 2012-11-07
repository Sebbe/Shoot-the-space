#ifndef BASESHIP_H
#define BASESHIP_H

#include "../Renderable.h"
#include "../Utils/Vector3D.h"
#include "../Bullet.h"
#include "../Collision/Collideable.h"
#include "../Bulletpool.h"

class BaseShip : public Renderable, public Collideable {
public:
	BaseShip(Vector3D<float> position);
	virtual ~BaseShip();
	virtual void Render() = 0;
	virtual void Shoot() { }
	virtual void Move() { }
	void SetType(CollisionBox::CollisionTypes type);
	virtual bool Delete();
	virtual void Update(float deltaTime);
	virtual CollisionBox* GetCollisionBox();
	virtual void Collision(CollisionBox*);
	virtual bool CheckCollision(Vector3D<float> checkCol, int side);
	bool IsActive();
	virtual void Active(bool isActive) { active = isActive; }
	Vector3D<float> getColBox();

	virtual bool GetLifeLeft();
	virtual void SetLifeLeft(int life);
	virtual void AddLifeLeft(int life);
	virtual void DecresLifeLeft(int life);
	virtual void SetBulletpool(Bulletpool *manager) { };
protected:
	CollisionBox _collisionBox;
	Vector3D<float> colBox;
	bool active;
	int iLife;
};

#endif