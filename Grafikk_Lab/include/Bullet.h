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
protected:
	GLfloat vertices[72];
	float rotQube;
	void drawCube();
	
	float degrees;
	void drawQuad();
};

#endif