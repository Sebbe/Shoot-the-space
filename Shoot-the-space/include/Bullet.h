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
	GLfloat verticess[3];
protected:
	GLfloat vertices[12];
};

#endif