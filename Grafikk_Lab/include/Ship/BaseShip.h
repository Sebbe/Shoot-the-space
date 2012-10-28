#ifndef BASESHIP_H
#define BASESHIP_H

#include "../Renderable.h"
#include "../Utils/Vector3D.h"
#include "../Bullet.h"

class BaseShip : public Renderable {
public:
	BaseShip(Vector3D<float> position);
	virtual ~BaseShip();
	virtual void Render() = 0;
	virtual void Shoot() { }
	virtual void Move() { }
	virtual void Update(float deltaTime);
	virtual bool CheckCollision(BaseShip *otShip);
	virtual bool CheckCollision(Bullet *aBullet);
	virtual bool CheckCollision(Vector3D<float> checkCol, int side);

	bool IsActive();
	void Active(bool isActive) { active = isActive; }
	Vector3D<float> getColBox();
protected:
	Vector3D<float> colBox;
	bool active;
};

#endif