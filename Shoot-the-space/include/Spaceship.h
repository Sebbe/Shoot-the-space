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
#include "InputManager.h"

class Spaceship : public Renderable {
public:
	Spaceship(InputManager *inputManager);
	~Spaceship();
	void Shoot();
	void Update(double deltaTime);
	void Render();
	void Move(double deltaTime);
protected:
	GLfloat vertices[9];
	InputManager *input;
};

#endif