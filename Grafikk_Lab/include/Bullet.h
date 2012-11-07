#ifndef BULLET_H
#define BULLET_H

#include <SDL.h>

#include "Renderable.h"
#include "Updateable.h"
#include "Collision\CollisionBox.h"
#include "Collision\Collideable.h"

class Bullet : public Renderable, public Collideable {
public:
	Bullet(GLfloat shipX, GLfloat shipY, GLfloat shipZ);
	~Bullet();
	void Update(double deltaTime);
	void Render();
	bool Delete();
	virtual void Collision(CollisionBox*);
	virtual CollisionBox* GetCollisionBox();
	void setX(GLfloat x);
	void setY(GLfloat y);
	void setZ(GLfloat z);
	void SetType(CollisionBox::CollisionTypes type);
	void SetActive(bool act);
	bool ShouldDeActivate();
protected:
	bool _shouldDeActivate;
	GLfloat vertices[72];
	float rotQube;
	CollisionBox _collisionBox;
	Vector3D<float> colBox;
	bool active;
};

#endif