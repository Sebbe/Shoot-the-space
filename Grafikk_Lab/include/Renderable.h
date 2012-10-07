#ifndef RENDERABLE_H
#define RENDERABLE_H

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

using std::cerr;
using std::endl;
using GLUtils::checkGLErrors;

class Renderable {
public:
	Renderable() {}
	virtual ~Renderable() {}
	virtual void Render() {
		std::cout << "test";
	}

	virtual void Update(double deltaTime) {
		std::cout << "feil ";
	};

	virtual bool Delete() {
		return false;
	}

	GLfloat inline getX() { return x; }
	GLfloat inline getY() { return y; }
	GLfloat inline getZ() { return z; }
protected:
	GLfloat movementPS;
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

#endif