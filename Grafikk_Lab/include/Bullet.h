#ifndef BULLET_H
#define BULLET_H

#include <SDL.h>

#include "Renderable.h"
#include "Updateable.h"


class Bullet : public Renderable {
public:
	Bullet(GLfloat shipX, GLfloat shipY, GLfloat shipZ);
	~Bullet();
	void Update(double deltaTime);
	void Render();
	bool Delete();
	void setX(GLfloat x);
	void setY(GLfloat y);
	void setZ(GLfloat z);
protected:
	GLfloat vertices[72];
	float rotQube;
};

#endif