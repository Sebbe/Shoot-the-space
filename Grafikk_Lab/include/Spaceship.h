#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Renderable.h"
#include "Updateable.h"
#include "GLUtils/GLUtils.hpp"
#include <Windows.h>
#include <GL/GL.h>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <assert.h>
#include <stdexcept>
#include "Input/InputManager.h"
#include "Bulletpool.h"
#include "Ship\BaseShip.h"


class Spaceship : public BaseShip {
public:
	Spaceship(Bulletpool *bulletpool);
	~Spaceship();
	void Shoot();
	void Update(double deltaTime);
	void Render();
	void Move(double deltaTime);
	bool CheckCollision(Vector3D<float> checkCol, int side);
	virtual void Collision(CollisionBox*);
protected:
	GLfloat vertices[42];
	Bulletpool *bulletpool;
};

#endif